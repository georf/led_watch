#include <RTClib.h>
#include <Wire.h>
#include "Arduino.h"

// #define DEBUG true
#ifdef DEBUG
#define DPRINT(...) Serial.print(__VA_ARGS__)
#define DPRINTLN(...) Serial.println(__VA_ARGS__)
#else
#define DPRINT(...)
#define DPRINTLN(...)
#endif

#pragma once

enum Modus { CLOCK, HOURS, MINUTES };
