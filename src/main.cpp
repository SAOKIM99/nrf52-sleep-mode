#include <Arduino.h>
#include "nRF5x_lowPower.h"

#define PIN_BUTTON    0
#define PIN_LED       14

void wakeUpCallback () {
}


void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  attachInterrupt(PIN_BUTTON, wakeUpCallback, FALLING);
  nRF5x_lowPower.enableWakeupByInterrupt(PIN_BUTTON, FALLING);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_LED, LOW);
  delay(500);

  // POWER_MODE_OFF                // shuts down the nRF5x
  // POWER_MODE_LOW_POWER         // nRF5x low power mode
  // POWER_MODE_CONSTANT_LATENCY  // nRF5x constant latency mode
  nRF5x_lowPower.powerMode(POWER_MODE_OFF);
}