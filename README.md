Description
===========

This is an endpoint for IceC using a nRF24 transceiver, connected by
SPI interface. The endpoint type is `nrf24`, and it has two
parameters, `-c`, which is the channel where the nRF will listen, and
`-a`, the device address (up to 5 ascii chars). Thus, an stringfied
proxy should look like the following:

    Car -e 1.0 -d:nrf24 -c 100 -a car1

See `example` dir for an example of its usage and configuration
sample files.


Arduino package
===============

To install this library, first create a library for Arduino:

    $ make arduino-package

Then, using your library manager (Arduino IDE, PlatformIO, etc),
install it.


References
==========

* nRF24 library and docs: https://github.com/tmrh20/RF24
