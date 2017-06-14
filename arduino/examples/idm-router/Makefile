# -*- mode: makefile; coding: utf-8 -*-

all:

run-router:
	idm-router --Ice.Config=router.config

run-station:
	./station.py --Ice.Config=station.config

.PHONY: clean
clean:
	$(RM) router.table *.pyc *~
