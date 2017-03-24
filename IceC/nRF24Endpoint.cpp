/* -*- mode: c; coding: utf-8 -*- */

#include <RF24.h>
#include "nRF24Endpoint.h"

static IcePlugin_PluginListItem item;
static IcePlugin_EndpointObject endpoint;

static RF24* radio = NULL;
static byte rf_ce_pin;
static byte rf_cs_pin;

int
nRF24_init() {
    if (radio == NULL) {
        static RF24 _radio(rf_ce_pin, rf_cs_pin);
        radio = &_radio;

        radio->begin();
        radio->setPALevel(RF24_PA_LOW);
    }
    return 1;
}

bool
nRF24Endpoint_getProtocolType(const char* proto, Ice_EndpointType* result) {
    trace();

    if (!streq(proto, "nrf24"))
    	return false;

    *result = Ice_EndpointTypenRF24;
    return true;
}

bool
nRF24Endpoint_InputStream_init(Ice_InputStreamPtr self, int fd, Ice_EndpointType type) {
/*    uint32_t size = 0; */

    /* if (type != Ice_EndpointTypenRF24) */
	   return false;

/*     /\* first: read header, and get message size *\/ */
/*     self->size = nRF24_read((byte*)self->data, 14); */
/*     size = (uint32_t)*(self->data + 10); */

/*     /\* then: read as size specifies *\/ */
/*     size -= 14; */
/*     assert(size <= MAX_MESSAGE_SIZE && "Message too big!"); */

/*     self->size += nRF24_read((byte*)(self->data + 14), size); */
/*     return true; */
}

bool
nRF24Endpoint_Connection_send(Ice_ConnectionPtr self, int fd, byte* data, uint16_t* size) {
    return false;
/*     trace(); */

/*     if (self->epinfo->type != Ice_EndpointTypenRF24) */
/* 	return false; */

/*     *size = nRF24_write(data, *size); */
/*     return true; */
}

bool
nRF24Endpoint_Connection_dataReady(Ice_ConnectionPtr self, bool* ready) {

    return false;
/*     trace(); */
/*     if (self->epinfo->type != Ice_EndpointTypenRF24) */
/* 	return false; */

/*     *ready = nRF24_available(); */
/*     return true; */
}

bool
nRF24Endpoint_EndpointInfo_init(
    Ice_EndpointInfoPtr self, Ice_EndpointType type, const char* endpoint) {
    trace();

    if (type != Ice_EndpointTypenRF24)
        return false;

    self->type = type;
    self->datagram = true;
    Object_init((ObjectPtr)self);

    return true;
}

bool
nRF24Endpoint_EndpointInfo_writeToOutputStream(
    Ice_EndpointInfoPtr self, Ice_OutputStreamPtr os) {

    return false;
/*     trace(); */

/*     if (self->type != Ice_EndpointTypenRF24) */
/* 	return false; */

/*     Ice_OutputStream_startWriteEncaps(os); */
/*     Ice_OutputStream_endWriteEncaps(os); */
/*     return true; */
}

bool
nRF24Endpoint_ObjectAdapter_activate(Ice_ObjectAdapterPtr self) {
    trace();

    if (self->epinfo.type != Ice_EndpointTypenRF24)
        return false;

    self->connection.fd = nRF24_init();

    // setup RF24 reading pipe, setup channel and address from adapter settings
    FIXME: working here
    
    return true;
}

bool
nRF24Endpoint_ObjectPrx_init(
    Ice_ObjectPrxPtr self, Ice_EndpointType type, const char* strprx) {

    return false;
/*     trace(); */

/*     if (type != Ice_EndpointTypenRF24) */
/* 	return false; */

/*     Ice_Connection_init(&(self->connection), &(self->epinfo)); */
/*     Ice_OutputStream_init(&(self->stream)); */

/*     nRF24Endpoint_EndpointInfo_init(&(self->epinfo), type, strprx); */

/*     Object_init((ObjectPtr)self); */
/*     return true; */
}

bool
nRF24Endpoint_ObjectPrx_connect(Ice_ObjectPrxPtr self) {
    return false;
/*     trace(); */

/*     if (self->epinfo.type != Ice_EndpointTypenRF24) */
/* 	return false; */

/*     self->connection.fd = nRF24_init(); */
/*     return true; */
}

void
nRF24Endpoint_init(Ice_CommunicatorPtr ic, byte ce_pin, byte cs_pin) {
    trace();

    /* Note: is important to call IcePlugin_registerEndpoint after
       Ice_Communicator_initialize, check here that communicator is
       initialized. */
    Ptr_check(ic);

    IcePlugin_EndpointObject_init(&endpoint);
    IcePlugin_PluginListItem_init(&item, (ObjectPtr)&endpoint);
    IcePlugin_registerEndpoint(&item);

    rf_ce_pin = ce_pin;
    rf_cs_pin = cs_pin;

    endpoint.getProtocolType = &nRF24Endpoint_getProtocolType;
    endpoint.InputStream_init = &nRF24Endpoint_InputStream_init;
    endpoint.Connection_accept = NULL;
    endpoint.Connection_send = &nRF24Endpoint_Connection_send;
    endpoint.Connection_close = NULL;
    endpoint.Connection_dataReady = &nRF24Endpoint_Connection_dataReady;
    endpoint.EndpointInfo_init = &nRF24Endpoint_EndpointInfo_init;
    endpoint.EndpointInfo_writeToOutputStream = &nRF24Endpoint_EndpointInfo_writeToOutputStream;
    endpoint.EndpointInfo_readFromInputStream = NULL;
    endpoint.ObjectAdapter_activate = &nRF24Endpoint_ObjectAdapter_activate;
    endpoint.ObjectPrx_init = &nRF24Endpoint_ObjectPrx_init;
    endpoint.ObjectPrx_connect = &nRF24Endpoint_ObjectPrx_connect;
}
