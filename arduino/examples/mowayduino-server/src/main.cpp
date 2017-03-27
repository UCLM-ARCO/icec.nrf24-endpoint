// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <SPI.h>
#include <EEPROM.h>
// #include <RF24.h>

// #include <MowayduinoRobot.h>
#include <IceC.h>
#include <nRF24Endpoint.h>

#include "robot.h"

// These pins are for Arduino Nano
#define RF_CE 7
#define RF_CS 8

// These pins are for Mowayduino robot
// #define RF_CE 0
// #define RF_CS 17

// mowayduinorobot robot;

Ice_Communicator ic;
Ice_ObjectAdapter adapter;
Robot_Motion servant;

void setup() {
    Serial.begin(115200);
    // robot.beginMowayduino();

    /* init and setup communicator */
    Ice_initialize(&ic);
    nRF24Endpoint_init(&ic, RF_CE, RF_CS);

    /* create object adapter */
    Ice_Communicator_createObjectAdapterWithEndpoints
        (&ic, "Adapter", "nrf24 -c 100 -a car1", &adapter);
    Ice_ObjectAdapter_activate(&adapter);

    /* register servant */
    Robot_Motion_init(&servant);
    Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "car01");
    print_dbg("Setup Finished!\n");
}

void loop() {
    Ice_Communicator_loopIteration(&ic);
    delay(1000);
}

void
Robot_MotionI_forward(int time) {
}

void
Robot_MotionI_backward(int time) {
}
