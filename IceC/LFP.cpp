// -*- mode: c++; coding: utf-8 -*-

#include "LFP.h"

uint16_t LFP_read_packet(RF24* radio, byte* dst, uint16_t max_size) {
    // first: read header and check if is a whole message or fragmented
    byte radio_size = radio->getPayloadSize();
    byte buff[radio_size];
    radio->read(buff, radio_size);

    // not fragmented message
    if (buff[0] == 'I') {
        uint32_t size = (uint32_t)*(buff + 10);
        assert(size <= min(max_size, radio_size) && "Too big message!");

        memcpy(dst, buff, size);
        return size;
    }

    // fragmented message
    else if (buff[0] == LFP_MAGIC) {
        LFPPacketPtr packet = (LFPPacketPtr)buff;
        byte header_size = sizeof(LFPPacket);

        // check that message will fit in size and copy packet payload
        uint32_t size = (uint32_t)*(buff + 10 + header_size);
        assert(size <= max_size && "Too big message!");

        byte expected_node_id = packet->node_id;
        byte expected_frame = packet->frame_id;
        byte i = packet->total_frames - 1;

        do {
            // print_dbg(" - frame id: ");
            // printi_dbg(packet->frame_id);
            // print_dbg("\n");

            if (packet->node_id == expected_node_id &&
                packet->frame_id == expected_frame) {

                memcpy(dst, buff + header_size, packet->frame_size);
                dst += packet->frame_size;
            }

            // read next packet (if any)
            if (i) {
                byte elapsed = LFP_MAX_WAITING_TIME;
                while (elapsed-- && !radio->available())
                    delay(1);

                // if message does not arrive on time, discard it
                if (!radio->available()) {
                    // print_dbg(" - not enough packets!\n");
                    return 0;
                }
                radio->read(buff, radio_size);
            }
            expected_frame++;

        } while (i--);
        // print_dbg(" - return size: ");
        // printi_dbg(size);
        // print_dbg("\n");

        return size;
    }

    // bad message format, discard
    else {
        // print_dbg(" - bad message\n");
        return 0;
    }
}

uint16_t LFP_write_packet(RF24* radio, byte* src, uint16_t size) {
    // check if no LFP needed
    if (size <= radio->getPayloadSize()) {
        radio->stopListening();
        radio->write(src, size);
        radio->startListening();
        return size;
    }

    // LFP needed, split payload into chunks and send them
    byte chunk_size = radio->getPayloadSize() - sizeof(LFPPacket);
    byte total_frames = size / chunk_size;
    if (size % chunk_size)
        total_frames++;

    randomSeed(analogRead(0));
    byte node_id = random(255);

    byte buff[32];
    LFPPacketPtr packet = (LFPPacketPtr) buff;
    packet->magic = LFP_MAGIC;
    packet->node_id = node_id;
    packet->total_frames = total_frames;

    radio->stopListening();
    for (byte i=1; i<=total_frames; i++) {
        packet->frame_size = chunk_size;
        if (i == total_frames)
            packet->frame_size = size % chunk_size;

        packet->frame_id = i;
        memcpy(
            buff + sizeof(LFPPacket),
            src + (i-1) * chunk_size,
            packet->frame_size);

        if (!radio->write(buff, sizeof(LFPPacket) + packet->frame_size)) {
            radio->startListening();
            return 0;
        }
    }
    radio->startListening();

    return size;
}
