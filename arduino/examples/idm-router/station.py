#!/usr/bin/env python3
# -*- mode: python; coding: utf-8 -*-

import sys
import Ice

Ice.loadSlice("/usr/share/slice/idm/idm.ice")
import IDM

Ice.loadSlice("robot.ice")
import Robot


class StationI(Robot.Station):
    def notifyBatteryLevel(self, level, current):
        print("notify of battery level: {}".format(level))


class Server(Ice.Application):
    def run(self, args):
        ic = self.communicator()

        adapter = ic.createObjectAdapter("Adapter")
        adapter.activate()

        oid = ic.getProperties().getProperty("IDM.Address")
        prx = adapter.add(StationI(), ic.stringToIdentity(oid))
        self.register_on_router(prx)
        print("Proxy: '{}'".format(prx))

        print("Waiting events...")
        self.shutdownOnInterrupt()
        ic.waitForShutdown()

    def register_on_router(self, proxy):
        ic = self.communicator()
        router = ic.propertyToProxy("IDM.Router.Proxy")
        router = IDM.NeighborDiscovery.ListenerPrx.checkedCast(router)

        router.adv(ic.proxyToString(proxy))


if __name__ == "__main__":
    Server().main(sys.argv)
