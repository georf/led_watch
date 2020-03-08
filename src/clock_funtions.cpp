#include "Arduino.h"

uint8_t clock_hours_led(uint8_t minutes, uint8_t hours) {
  if (minutes > 12) hours += 1;
  if (hours >= 12) hours = 0;
  return hours;
}

bool clock_uhr(uint8_t minutes) {
  return minutes == 0 || minutes == 1 || minutes == 2 || minutes == 3 ||
         minutes == 4 || minutes == 5 || minutes == 6 || minutes == 7 ||
         minutes == 8 || minutes == 9 || minutes == 10 || minutes == 11 ||
         minutes == 12 || minutes == 48 || minutes == 49 || minutes == 50 ||
         minutes == 51 || minutes == 52 || minutes == 53 || minutes == 54 ||
         minutes == 55 || minutes == 56 || minutes == 57 || minutes == 58 ||
         minutes == 59;
}

bool clock_fuenf(uint8_t minutes) {
  return minutes == 3 || minutes == 4 || minutes == 5 || minutes == 6 ||
         minutes == 7 || minutes == 23 || minutes == 24 || minutes == 25 ||
         minutes == 26 || minutes == 27 || minutes == 33 || minutes == 34 ||
         minutes == 35 || minutes == 36 || minutes == 37 || minutes == 53 ||
         minutes == 54 || minutes == 55 || minutes == 56 || minutes == 57;
}

bool clock_zehn(uint8_t minutes) {
  return minutes == 8 || minutes == 9 || minutes == 10 || minutes == 11 ||
         minutes == 12 || minutes == 18 || minutes == 19 || minutes == 20 ||
         minutes == 21 || minutes == 22 || minutes == 38 || minutes == 39 ||
         minutes == 40 || minutes == 41 || minutes == 42 || minutes == 48 ||
         minutes == 49 || minutes == 50 || minutes == 51 || minutes == 52;
}

bool clock_viertel(uint8_t minutes) {
  return minutes == 13 || minutes == 14 || minutes == 15 || minutes == 16 ||
         minutes == 17 || minutes == 43 || minutes == 44 || minutes == 45 ||
         minutes == 46 || minutes == 47;
}

bool clock_minuten(uint8_t minutes) {
  return minutes == 3 || minutes == 4 || minutes == 5 || minutes == 6 ||
         minutes == 7 || minutes == 8 || minutes == 9 || minutes == 10 ||
         minutes == 11 || minutes == 12 || minutes == 18 || minutes == 19 ||
         minutes == 20 || minutes == 21 || minutes == 22 || minutes == 23 ||
         minutes == 24 || minutes == 25 || minutes == 26 || minutes == 27 ||
         minutes == 33 || minutes == 34 || minutes == 35 || minutes == 36 ||
         minutes == 37 || minutes == 38 || minutes == 39 || minutes == 40 ||
         minutes == 41 || minutes == 42 || minutes == 48 || minutes == 49 ||
         minutes == 50 || minutes == 51 || minutes == 52 || minutes == 53 ||
         minutes == 54 || minutes == 55 || minutes == 56;
}

bool clock_vor(uint8_t minutes) {
  return minutes == 18 || minutes == 19 || minutes == 20 || minutes == 21 ||
         minutes == 22 || minutes == 23 || minutes == 24 || minutes == 25 ||
         minutes == 26 || minutes == 27 || minutes == 43 || minutes == 44 ||
         minutes == 45 || minutes == 46 || minutes == 47 || minutes == 48 ||
         minutes == 49 || minutes == 50 || minutes == 51 || minutes == 52 ||
         minutes == 53 || minutes == 54 || minutes == 55 || minutes == 56 ||
         minutes == 57;
}

bool clock_nach(uint8_t minutes) {
  return minutes == 3 || minutes == 4 || minutes == 5 || minutes == 6 ||
         minutes == 7 || minutes == 8 || minutes == 9 || minutes == 10 ||
         minutes == 11 || minutes == 12 || minutes == 33 || minutes == 34 ||
         minutes == 35 || minutes == 36 || minutes == 37 || minutes == 38 ||
         minutes == 39 || minutes == 40 || minutes == 41 || minutes == 42;
}

bool clock_halb(uint8_t minutes) {
  return

      minutes == 18 || minutes == 19 || minutes == 20 || minutes == 21 ||
      minutes == 22 || minutes == 23 || minutes == 24 || minutes == 25 ||
      minutes == 26 || minutes == 27 || minutes == 28 || minutes == 29 ||
      minutes == 30 || minutes == 31 || minutes == 32 || minutes == 33 ||
      minutes == 34 || minutes == 35 || minutes == 36 || minutes == 37 ||
      minutes == 38 || minutes == 39 || minutes == 40 || minutes == 41 ||
      minutes == 42;
}