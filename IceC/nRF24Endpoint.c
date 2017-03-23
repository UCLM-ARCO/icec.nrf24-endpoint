/* -*- mode: c; coding: utf-8 -*- */

/* #include <IceC/SerialEndpoint.h> */
/* #include <IceC/SerialIO.h> */

/* static IcePlugin_PluginListItem item; */
/* static IcePlugin_EndpointObject endpoint; */

/* bool */
/* SerialEndpoint_getProtocolType(const char* proto, Ice_EndpointType* result) { */
/*     trace(); */

/*     if (!streq(proto, "serial")) */
/*     	return false; */

/*     *result = Ice_EndpointTypeSerial; */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_InputStream_init(Ice_InputStreamPtr self, int fd, Ice_EndpointType type) { */
/*     uint32_t size = 0; */

/*     trace(); */

/*     if (type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     /\* first: read header, and get message size *\/ */
/*     self->size = Serial_read((byte*)self->data, 14); */
/*     size = (uint32_t)*(self->data + 10); */

/*     /\* then: read as size specifies *\/ */
/*     size -= 14; */
/*     assert(size <= MAX_MESSAGE_SIZE && "Message too big!"); */

/*     self->size += Serial_read((byte*)(self->data + 14), size); */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_ObjectAdapter_activate(Ice_ObjectAdapterPtr self) { */
/*     trace(); */

/*     if (self->epinfo.type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     self->connection.fd = Serial_init(); */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_EndpointInfo_init(Ice_EndpointInfoPtr self, Ice_EndpointType type, */
/* 				 const char* endpoint) { */
/*     trace(); */

/*     if (type != Ice_EndpointTypeSerial) */
/*     	return false; */

/*     self->type = type; */
/*     self->datagram = true; */
/*     Object_init((ObjectPtr)self); */

/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_EndpointInfo_writeToOutputStream(Ice_EndpointInfoPtr self, */
/* 						Ice_OutputStreamPtr os) { */
/*     trace(); */

/*     if (self->type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     Ice_OutputStream_startWriteEncaps(os); */
/*     Ice_OutputStream_endWriteEncaps(os); */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_ObjectPrx_connect(Ice_ObjectPrxPtr self) { */
/*     trace(); */

/*     if (self->epinfo.type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     self->connection.fd = Serial_init(); */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_ObjectPrx_init(Ice_ObjectPrxPtr self, Ice_EndpointType type, */
/* 			      const char* strprx) { */
/*     trace(); */

/*     if (type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     Ice_Connection_init(&(self->connection), &(self->epinfo)); */
/*     Ice_OutputStream_init(&(self->stream)); */

/*     SerialEndpoint_EndpointInfo_init(&(self->epinfo), type, strprx); */

/*     Object_init((ObjectPtr)self); */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_Connection_send(Ice_ConnectionPtr self, int fd, byte* data, uint16_t* size) { */
/*     trace(); */

/*     if (self->epinfo->type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     *size = Serial_write(data, *size); */
/*     return true; */
/* } */

/* bool */
/* SerialEndpoint_Connection_dataReady(Ice_ConnectionPtr self, bool* ready) { */
/*     trace(); */
/*     if (self->epinfo->type != Ice_EndpointTypeSerial) */
/* 	return false; */

/*     *ready = Serial_available(); */
/*     return true; */
/* } */

/* void */
/* SerialEndpoint_init(Ice_CommunicatorPtr ic) { */
/*     trace(); */

/*     /\* Note: is important to call IcePlugin_registerEndpoint after */
/*        Ice_Communicator_initialize, check here that communicator is */
/*        initialized. *\/ */
/*     Ptr_check(ic); */

/*     IcePlugin_EndpointObject_init(&endpoint); */
/*     IcePlugin_PluginListItem_init(&item, (ObjectPtr)&endpoint); */
/*     IcePlugin_registerEndpoint(&item); */

/*     endpoint.getProtocolType = &SerialEndpoint_getProtocolType; */
/*     endpoint.InputStream_init = &SerialEndpoint_InputStream_init; */
/*     endpoint.ObjectAdapter_activate = &SerialEndpoint_ObjectAdapter_activate; */
/*     endpoint.EndpointInfo_init = &SerialEndpoint_EndpointInfo_init; */
/*     endpoint.EndpointInfo_writeToOutputStream = &SerialEndpoint_EndpointInfo_writeToOutputStream; */
/*     endpoint.ObjectPrx_init = &SerialEndpoint_ObjectPrx_init; */
/*     endpoint.ObjectPrx_connect = &SerialEndpoint_ObjectPrx_connect; */
/*     endpoint.Connection_accept = NULL; */
/*     endpoint.Connection_send = &SerialEndpoint_Connection_send; */
/*     endpoint.Connection_close = NULL; */
/*     endpoint.Connection_dataReady = &SerialEndpoint_Connection_dataReady; */
/* } */
