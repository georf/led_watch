#include "base.h"

class ClockHandling {
 public:
  void startup();
  void btnModusPressed();
  void btnSetPressed();
  boolean normalMode();
  uint8_t getNumber();
  uint8_t getHour();
  uint8_t getMinute();
  Modus modus;

 private:
  RTC_DS1307 rtc_;
  void increaseHour();
  void increaseMinute();
  uint32_t fallbackTime;
};