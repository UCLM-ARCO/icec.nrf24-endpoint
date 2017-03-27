// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
#include <SPI.h>
#include <EEPROM.h>
#include <RF24.h>

#include "MowayduinoRobot.h"

#define RF_CE 0
#define RF_CS 17

mowayduinorobot robot;
RF24 radio(RF_CE, RF_CS);
byte dst_address[6] = "car01";
byte src_address[6] = "sendr";

void led_error() {
    robot.Ledsoff();
    robot.Redon();
    delay(100);
    robot.Ledsoff();
    delay(500);
}

void led_ok() {
    robot.Ledsoff();
    robot.Greenon();
    delay(50);
    robot.Ledsoff();
}

void setup() {
    robot.beginMowayduino();
    robot.Ledsoff();

    radio.begin();
    radio.setPALevel(RF24_PA_LOW);
    radio.openWritingPipe(dst_address);
    radio.openReadingPipe(1, src_address);
    radio.stopListening();
}

void loop() {
    const char* data = "blue";
    if (not radio.write(data, strlen(data)))
        led_error();
    else
        led_ok();

    delay(500);
}
