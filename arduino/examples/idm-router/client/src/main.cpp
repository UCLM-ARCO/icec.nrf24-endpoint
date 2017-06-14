// -*- mode: c++; coding; utf-8 -*-

#include <Arduino.h>
#include <EEPROM.h>

#include <IceC.h>
#include <RF24.h>
#include <nRF24Endpoint.h>
#include <MowayduinoRobot.h>

#include "robot.h"

// Mowayduino pins
#define CE_PIN 0
#define CS_PIN 17

mowayduinorobot robot;

Ice_Communicator ic;
Ice_ObjectPrx station;

void send_battery_level() {
    byte level = robot.readBatt();
    Robot_Station_notifyBatteryLevel(&station, level);

    robot.Greenon();
    delay(50);
    robot.Ledsoff();
}

void setup() {
    robot.beginMowayduino();
    robot.Ledsoff();

    // init and setup communicator
    Ice_initialize(&ic);
    nRF24Endpoint_init(&ic, CE_PIN, CS_PIN);

    // create proxy to remote object
    Ice_Communicator_stringToProxy(
        &ic, "5F02 -d:nrf24 -c 90 -a idm", &station);
}

void loop() {
    send_battery_level();
    delay(5000);
}
