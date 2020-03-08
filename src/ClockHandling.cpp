#include "ClockHandling.h"

void ClockHandling::startup() {
  modus = CLOCK;
  fallbackTime = millis();

  rtc_ = RTC_DS1307();
  if (!rtc_.begin()) {
    DPRINTLN("Couldn't find RTC");
    while (1)
      ;
  }

  if (!rtc_.isrunning()) {
    DPRINTLN("RTC is NOT running!");
  }
}

void ClockHandling::btnModusPressed() {
  fallbackTime = millis();

  if (modus == HOURS) {
    modus = MINUTES;
  } else if (modus == CLOCK || modus == MINUTES) {
    modus = HOURS;
  }
}

void ClockHandling::btnSetPressed() {
  fallbackTime = millis();

  if (modus == HOURS) {
    increaseHour();
  } else if (modus == MINUTES) {
    increaseMinute();
  }
}

boolean ClockHandling::normalMode() {
  if ((fallbackTime + 5000) < millis()) {
    modus = CLOCK;
    return true;
  }
  return false;
}

uint8_t ClockHandling::getNumber() {
  if (modus == HOURS) {
    return rtc_.now().hour();
  } else if (modus == MINUTES) {
    return rtc_.now().minute();
  }
  return 0;
}

void ClockHandling::increaseHour() {
  DateTime oldDt = rtc_.now();
  DateTime newDt =
      DateTime(oldDt.year(), oldDt.month(), oldDt.day(),
               (oldDt.hour() + 1) % 12, oldDt.minute(), oldDt.second());
  rtc_.adjust(newDt);
}

void ClockHandling::increaseMinute() {
  DateTime oldDt = rtc_.now();
  DateTime newDt =
      DateTime(oldDt.year(), oldDt.month(), oldDt.day(), oldDt.hour(),
               (oldDt.minute() + 1) % 60, oldDt.second());
  rtc_.adjust(newDt);
}

uint8_t ClockHandling::getHour() { return rtc_.now().hour() % 12; }

uint8_t ClockHandling::getMinute() { return rtc_.now().minute(); }