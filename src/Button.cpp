#include "Button.h"

Button::Button(uint8_t pin) {
  _pin = pin;
}

void Button::begin() {
  pinMode(_pin, INPUT_PULLUP);
}

void Button::update() {
}
