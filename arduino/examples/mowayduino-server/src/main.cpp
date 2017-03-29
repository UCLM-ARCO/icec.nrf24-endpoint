// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <SPI.h>
#include <EEPROM.h>
#include <RF24.h>

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
    Serial.println("Booting...");
    // robot.beginMowayduino();

    /* init and setup communicator */
    Ice_initialize(&ic);
    nRF24Endpoint_init(&ic, RF_CE, RF_CS);

    /* create object adapter */
    Ice_Communicator_createObjectAdapterWithEndpoints
        (&ic, "Adapter", "nrf24 -c 100 -a car01", &adapter);
    Ice_ObjectAdapter_activate(&adapter);

    /* register servant */
    Robot_Motion_init(&servant);
    Ice_ObjectAdapter_add(&adapter, (Ice_ObjectPtr)&servant, "Car1");
}

void loop() {
    Ice_Communicator_loopIteration(&ic);
}

void
Robot_MotionI_forward(Robot_MotionPtr self, Ice_Int time) {
    Serial.println("forward called!");
}

void
Robot_MotionI_backward(Robot_MotionPtr self, Ice_Int time) {
    Serial.println("backward called!");
}
