#pragma once

#include <Arduino.h>

class Button {
public:
  Button(uint8_t pin);

  void begin();
  void update();

private:
  uint8_t _pin;
};
