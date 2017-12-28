/**
  ntp.h - Network Time Protocol

  Copyright (c) 2017 Costin STROIE <costinstroie@eridu.eu.org>

  This file is part of WiFi_APRS_Tracker.
*/

#ifndef NTP_H
#define NTP_H

#include "Arduino.h"
#include <WiFiUdp.h>

class NTP {
  public:
    NTP();
    void          init(char *server);
    void          init(const char *server, int port = 123);
    void          setServer(const char *server, int port = 123);
    unsigned long timeUNIX(bool sync = true);
    unsigned long uptime(char *buf, size_t len);
    bool          ntpOk       = false;                  // Flag to know the time is accurate
  private:
    unsigned long ntpSync();
    char          ntpServer[50];                        // NTP server to connect to (RFC5905)
    int           ntpPort     = 123;                    // NTP port
    unsigned long ntpNextSync = 0UL;                    // Next time to syncronize
    unsigned long ntpDelta    = 0UL;                    // Difference between real time and internal clock
    int           ntpTZ       = 0;                      // Time zone
};

#endif /* NTP_H */
