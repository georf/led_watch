#include "main.h"

ClockHandling clockHandling;

#define pinLatch 3
#define pinClock 2
#define pinData 4

#define pinDrei 5
#define pinFuenf 6
#define pinElf 7
#define pinBtn0 8
#define pinBtn1 9
#define pinUhr 13
#define pinLedLeft 10
#define pinLedRight 11

const uint8_t ledNumbers[] = {
    0b00000100,  // 0
    0b00011111,  // 1
    0b00100010,  // 2
    0b00001010,  // 3
    0b00011001,  // 4
    0b01001000,  // 5
    0b01000000,  // 6
    0b00001111,  // 7
    0b00000000,  // 8
    0b00001000,  // 9
};

uint32_t pressed = 0;
uint32_t lastUpdate = 0;
uint8_t ledShown = 0;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
#endif

  // set pins as output
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinData, OUTPUT);

  pinMode(pinDrei, OUTPUT);
  pinMode(pinFuenf, OUTPUT);
  pinMode(pinElf, OUTPUT);
  pinMode(pinUhr, OUTPUT);
  pinMode(pinLedLeft, OUTPUT);
  pinMode(pinLedRight, OUTPUT);

  // set button pins as input
  pinMode(pinBtn0, INPUT_PULLUP);
  pinMode(pinBtn1, INPUT_PULLUP);

  clockHandling.startup();
}

void loop() {
  if (pressed == 0 && digitalRead(pinBtn0) == LOW) {
    pressed = millis();
    DPRINTLN("btn0");
    clockHandling.btnModusPressed();
  }
  if (pressed == 0 && digitalRead(pinBtn1) == LOW) {
    pressed = millis();
    DPRINTLN("btn1");
    clockHandling.btnSetPressed();
  }
  if (pressed != 0 && (pressed + 100) < millis() &&
      digitalRead(pinBtn0) == HIGH && digitalRead(pinBtn1) == HIGH) {
    pressed = 0;
  }

  if (clockHandling.modus == CLOCK) {
    updateLedClock();
  } else {
    if (clockHandling.normalMode()) {
      lastUpdate = 0;
      updateLedClock();
    } else {
      updateLedNumber();
    }
  }
}

void updateLedNumber() {
  if ((lastUpdate + 5) > millis()) {
    return;
  }

  uint8_t number = clockHandling.getNumber();
  if (ledShown == 0) {
    number = number / 10;
  } else {
    number = number % 10;
  }

  digitalWrite(pinLatch, LOW);
  shiftOut(pinData, pinClock, MSBFIRST, 0);
  shiftOut(pinData, pinClock, MSBFIRST, 0);
  shiftOut(pinData, pinClock, MSBFIRST, ledNumbers[number]);
  digitalWrite(pinLatch, HIGH);

  digitalWrite(pinLedLeft, ledShown == 0);
  digitalWrite(pinLedRight, ledShown == 1);

  digitalWrite(pinDrei, LOW);
  digitalWrite(pinFuenf, LOW);
  digitalWrite(pinElf, LOW);
  digitalWrite(pinUhr, LOW);

  ledShown = !ledShown;
  lastUpdate = millis();
}

static byte ledEsIst[] = {0b00000010, 0b00000000};
static byte ledZehn[] = {0b00000001, 0b00000000};
static byte ledFuenf[] = {0b00000000, 0b00000010};
static byte ledViertel[] = {0b00000100, 0b00000000};
static byte ledMinuten = 0b10000000;
static byte ledVor[] = {0b00000000, 0b00000100};
static byte ledNach[] = {0b00001000, 0b00000000};
static byte ledHalb[] = {0b00000000, 0b00001000};

static byte ledHours[12][2] = {
    {0b01000000, 0b00000000},  // 12
    {0b00000000, 0b00000001},  // 1
    {0b00000000, 0b00010000},  // 2
    {0b00000000, 0b00000000},  // 3
    {0b00100000, 0b00000000},  // 4
    {0b00000000, 0b00000000},  // 5
    {0b00000000, 0b10000000},  // 6
    {0b00010000, 0b00000000},  // 7
    {0b00000000, 0b00100000},  // 8
    {0b10000000, 0b00000000},  // 9
    {0b00000000, 0b01000000},  // 10
    {0b00000000, 0b00000000},  // 11
};

void setBits(byte* pointer, boolean set, byte* mask) {
  if (set) {
    pointer[0] = pointer[0] | mask[0];
    pointer[1] = pointer[1] | mask[1];
  }
}

void updateLedClock() {
  if ((lastUpdate + 500) > millis()) {
    return;
  }

  uint8_t hour = clockHandling.getHour();
  uint8_t minute = clockHandling.getMinute();
  DPRINT("Stunde ");
  DPRINT(hour);
  DPRINT(" Minute ");
  DPRINTLN(minute);

  byte bits[2];

  uint8_t hoursLed = clock_hours_led(minute, hour);
  DPRINTLN(hoursLed);
  bits[0] = ledEsIst[0] | ledHours[hoursLed][0];
  bits[1] = ledEsIst[1] | ledHours[hoursLed][1];

  setBits(bits, clock_zehn(minute), ledZehn);
  setBits(bits, clock_fuenf(minute), ledFuenf);
  setBits(bits, clock_viertel(minute), ledViertel);
  setBits(bits, clock_vor(minute), ledVor);
  setBits(bits, clock_nach(minute), ledNach);
  setBits(bits, clock_halb(minute), ledHalb);

  digitalWrite(pinLatch, LOW);
  shiftOut(pinData, pinClock, MSBFIRST, bits[0]);
  shiftOut(pinData, pinClock, MSBFIRST, bits[1]);
  shiftOut(pinData, pinClock, MSBFIRST, clock_minuten(minute) ? ledMinuten : 0);
  digitalWrite(pinLatch, HIGH);

  digitalWrite(pinDrei, hoursLed == 3);
  digitalWrite(pinFuenf, hoursLed == 5);
  digitalWrite(pinElf, hoursLed == 11);
  digitalWrite(pinUhr, clock_uhr(minute));

  digitalWrite(pinLedLeft, LOW);
  digitalWrite(pinLedRight, LOW);

  lastUpdate = millis();
}