#include "LaserEmitter.h"

LaserEmitterClass::LaserEmitterClass() {
}

void LaserEmitterClass::begin(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  turnOff();
}

void LaserEmitterClass::turnOn() {
  digitalWrite(_pin, HIGH);
}

void LaserEmitterClass::turnOff() {
  digitalWrite(_pin, LOW);
}

LaserEmitterClass LaserEmitter;
