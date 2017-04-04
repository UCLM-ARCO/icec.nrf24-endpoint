// -*- mode: c++; coding: utf-8 -*-

#ifndef _LFP_H_
#define _LFP_H_

#include <Arduino.h>
#include <IceC/IceC.h>  // just for the assert
#include <RF24.h>

#define LFP_MAGIC 'N'
#define LFP_MAX_WAITING_TIME 200

// Lightweight Fragmentation Protocol
typedef struct LFPPacket {
    byte magic;          // 'N' (for Nordic RF24)
    byte node_id;        // 'unique' node identifier
    byte frame_size;     // size of payload, WITHOUT header
    byte frame_id;       // identifier of this frame
    byte total_frames;   // total amount of expected frames
} LFPPacket;

typedef LFPPacket* LFPPacketPtr;

uint16_t LFP_read_packet(RF24* radio, byte* dst, uint16_t max_size);
uint16_t LFP_write_packet(RF24* radio, byte* src, uint16_t size);

#endif  // _LFP_H_
