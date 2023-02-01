#include <Arduino.h>

#include "badgepirates/factory.hpp"
#include "config.hpp"

#ifdef FACTORY_MODE
    Factory factory;
  #endif

void setup() {
  Serial.begin(115200);

  #ifdef FACTORY_MODE
    factory.setup();
  #endif
}

void loop() {
  #ifdef FACTORY_MODE
    factory.loop();
  #endif
}