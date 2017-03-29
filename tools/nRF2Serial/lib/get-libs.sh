#!/bin/bash
# -*- mode: sh; coding: utf-8 -*-

echo -n "IceC... "
if [ ! -d IceC ]; then
    wget -q https://bitbucket.org/arco_group/icec/downloads/arduino-icec-latest.zip
    unzip -qq arduino-icec-latest.zip
    rm arduino-icec-latest.zip
    echo "[ok] "
else
    echo "[already present]"
fi

echo -n "RF24... "
if [ ! -d RF24 ]; then
    wget -q https://github.com/TMRh20/RF24/archive/master.zip -O RF24.zip
    unzip -qq RF24.zip
    mv RF24-master RF24
    rm RF24.zip
    echo "[ok] "
else
    echo "[already present]"
fi
