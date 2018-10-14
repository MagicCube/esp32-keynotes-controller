#include "LaserLight.h"

#include "log.h"

LaserLight::LaserLight(uint8_t pin) {
  _pin = pin;
}

void LaserLight::begin() {
  pinMode(_pin, OUTPUT);
  turnOff();
}

void LaserLight::turnOn() {
  if (!_on) {
    _on = true;
    digitalWrite(_pin, HIGH);
  }
}

void LaserLight::turnOff() {
  if (_on) {
    _on = false;
    digitalWrite(_pin, LOW);
  }
}
