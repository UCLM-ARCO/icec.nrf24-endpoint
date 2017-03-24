// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <EEPROM.h>

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.print("Hola");
    delay(1000);
}








// #include <SPI.h>


// #include <MowayduinoRobot.h>
// #include <IceC.h>
// #include <nRF24Endpoint.h>


// mowayduinorobot robot;

// Ice_Communicator ic;
// Ice_ObjectAdapter adapter;
// Robot_Motion servant;

// void setup() {
//     robot.beginMowayduino();

//     /* init and setup communicator */
//     Ice_initialize(&ic);
//     nRF24Endpoint_init(&ic);

//     /* create object adapter */
//     Ice_Communicator_createObjectAdapterWithEndpoints
//         (&ic, "Adapter", "nrf24 -c 100 -n car1", &adapter);
//     Ice_ObjectAdapter_activate(&adapter);

//     /* register servant */
//     Robot_Motion_init(&servant);
//     Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "car1");
// }

// void loop() {
//     Ice_Communicator_loopIteration(&ic);
// }

// void
// Robot_MotionI_forward(int time) {

// }

// void
// Robot_MotionI_backward(int time) {

// }
