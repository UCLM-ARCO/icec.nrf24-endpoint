/* -*- mode: c++; coding: utf-8 -*- */

#ifndef _nRF24ENDPOINT_ENDPOINT_H_
#define _nRF24ENDPOINT_ENDPOINT_H_

#include <IceC/IceC.h>

#ifdef __cplusplus
extern "C" {
#endif

#define Ice_EndpointTypenRF24 15

typedef struct nRF24Endpoint_Options {
    Object _base;
    bool used;

    byte channel;
    byte address[6];
} nRF24Endpoint_Options;

typedef nRF24Endpoint_Options* nRF24Endpoint_OptionsPtr;

bool nRF24Endpoint_getProtocolType(const char* proto, Ice_EndpointType* result);
bool nRF24Endpoint_InputStream_init(Ice_InputStreamPtr self, int fd, Ice_EndpointType type);
bool nRF24Endpoint_ObjectAdapter_activate(Ice_ObjectAdapterPtr self);
bool nRF24Endpoint_EndpointInfo_init(Ice_EndpointInfoPtr self,
                                     Ice_EndpointType type,
                                     const char* endpoint);

bool nRF24Endpoint_ObjectPrx_connect(Ice_ObjectPrxPtr self);
bool nRF24Endpoint_ObjectPrx_init(Ice_ObjectPrxPtr self,
                                  Ice_EndpointType type,
                                  const char* strprx);

bool nRF24Endpoint_Connection_send(Ice_ConnectionPtr self, int fd, byte* data,
                                   uint16_t* size);

/* plugin specific functions */
void nRF24Endpoint_init(Ice_CommunicatorPtr ic, byte ce_pin, byte cs_pin);

#ifdef __cplusplus
}
#endif

#endif  /* _nRF24ENDPOINT_ENDPOINT_H_ */
