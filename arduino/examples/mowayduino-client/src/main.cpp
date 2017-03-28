// -*- mode: c++; coding: utf-8 -*-

#include <Arduino.h>
// #include <SPI.h>
// #include <EEPROM.h>
// #include <RF24.h>
// #include <MowayduinoRobot.h>
// #include <IceC.h>
#include <nRF24Endpoint.h>
//
// #include "robot.h"
//
// // These pins are for Arduino Nano
// #define RF_CE 7
// #define RF_CS 8
//
// // These pins are for Mowayduino robot
// // #define RF_CE 0
// // #define RF_CS 17
//
// // mowayduinorobot robot;
//
// Ice_Communicator ic;
// Ice_ObjectPrx car1;

void setup() {
//     Serial.begin(115200);
//     Serial.println("Booting...");
//     // robot.beginMowayduino();
//
//     /* init and setup communicator */
//     Ice_initialize(&ic);
//     nRF24Endpoint_init(&ic, RF_CE, RF_CS);
//
//     /* create proxy to remote object */
//     Ice_Communicator_stringToProxy(
//         &ic, "Car1 -d:nrf24 -c 100 -a car01", &car1);
//     Serial.println("Setup done!");
}

void loop() {
//     delay(1000);
//     Robot_Motion_backward(&car1, 1000);
}







// // // Code as No-ICE server follows
// //
// // #include <Arduino.h>
// // #include <SPI.h>
// // #include <EEPROM.h>
// // #include <RF24.h>
// //
// // #include "MowayduinoRobot.h"
// //
// // #define RF_CE 0
// // #define RF_CS 17
// //
// // mowayduinorobot robot;
// // RF24 radio(RF_CE, RF_CS);
// // byte src_address[6] = "car01";
// // byte dst_address[6] = "sendr";
// //
// // void led_signal() {
// //     robot.Ledsoff();
// //     robot.Blueon();
// //     delay(100);
// //     robot.Ledsoff();
// // }
// //
// // void setup() {
// //     robot.beginMowayduino();
// //     robot.Ledsoff();
// //
// //     robot.Greenon();
// //     delay(50);
// //     robot.Ledsoff();
// //
// //     radio.begin();
// //     radio.setPALevel(RF24_PA_LOW);
// //     radio.setChannel(100);
// //     radio.openWritingPipe(dst_address);
// //     radio.openReadingPipe(1, src_address);
// //     radio.startListening();
// // }
// //
// // void loop() {
// //     char received[] = {0, 0, 0, 0, 0};
// //     while (radio.available()) {
// //         radio.read(received, 5);
// //         led_signal();
// //     }
// // }
//
//
//
// // Code as no-ICE client follows ---------------------------------------------
//
//
//
// // #include <Arduino.h>
// // #include <SPI.h>
// // #include <EEPROM.h>
// // #include <RF24.h>
// //
// // #include "MowayduinoRobot.h"
// //
// // #define RF_CE 0
// // #define RF_CS 17
// //
// // mowayduinorobot robot;
// // RF24 radio(RF_CE, RF_CS);
// // byte dst_address[6] = "car01";
// // byte src_address[6] = "sendr";
// //
// // void led_error() {
// //     robot.Ledsoff();
// //     robot.Redon();
// //     delay(100);
// //     robot.Ledsoff();
// //     delay(500);
// // }
// //
// // void led_ok() {
// //     robot.Ledsoff();
// //     robot.Greenon();
// //     delay(50);
// //     robot.Ledsoff();
// // }
// //
// // void setup() {
// //     robot.beginMowayduino();
// //     robot.Ledsoff();
// //
// //     radio.begin();
// //     radio.setPALevel(RF24_PA_LOW);
// //     radio.setChannel(100);
// //     radio.openWritingPipe(dst_address);
// //     radio.openReadingPipe(1, src_address);
// //     radio.stopListening();
// // }
// //
// // void loop() {
// //     const char* data = "blue";
// //     if (not radio.write(data, strlen(data)))
// //         led_error();
// //     else
// //         led_ok();
// //
// //     delay(500);
// // }
