// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <SPI.h>
#include <EEPROM.h>
#include <RF24.h>
#include <MowayduinoRobot.h>

#include <IceC.h>
#include <nRF24Endpoint.h>

#include "robot.h"

// These pins are for Arduino Nano
// #define RF_CE 7
// #define RF_CS 8

// These pins are for Mowayduino robot
#define RF_CE 0
#define RF_CS 17

mowayduinorobot robot;

Ice_Communicator ic;
Ice_ObjectPrx car1;

void setup() {
    robot.beginMowayduino();
    robot.Ledsoff();

    /* init and setup communicator */
    Ice_initialize(&ic);
    nRF24Endpoint_init(&ic, RF_CE, RF_CS);

    /* create proxy to remote object */
    Ice_Communicator_stringToProxy(
        &ic, "Car1 -d:nrf24 -c 100 -a car01", &car1);
}

void loop() {
    delay(1000);
    Robot_Motion_backward(&car1, 1000);

    robot.Greenon();
    delay(50);
    robot.Ledsoff();
}
