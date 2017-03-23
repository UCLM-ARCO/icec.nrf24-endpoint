# -*- mode: makefile-gmake; coding: utf-8 -*-

all:

arduino-package: ARDUINO_DIST=/tmp/icec-nrf24/arduino/nRF24Endpoint
arduino-package: clean
	$(RM) -rf $(ARDUINO_DIST)

	install -d $(ARDUINO_DIST)/src
	cp -r arduino/examples $(ARDUINO_DIST)
	cp -r IceC $(ARDUINO_DIST)/src/
	install -m 644 IceC/nRF24Endpoint.h $(ARDUINO_DIST)/src/
	install -m 644 arduino/keywords.txt $(ARDUINO_DIST)
	install -m 644 arduino/library.properties $(ARDUINO_DIST)

	cd $(ARDUINO_DIST)/..; zip -r arduino-nrf24-endpoint-$$(date +%Y%m%d).zip nRF24Endpoint
	mv $(ARDUINO_DIST)/../*.zip .

.PHONY: clean
clean:
	find -name "*.o" -delete
	find -name "*~" -delete
	$(RM) -f *.zip
