#include "LaserEmitter.h"

#include "log.h"

LaserEmitterClass::LaserEmitterClass() {
}

void LaserEmitterClass::begin(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  turnOff();
}

void LaserEmitterClass::turnOn() {
  digitalWrite(_pin, HIGH);
  LOG_D("Laser emitter has been turned <ON>.");
}

void LaserEmitterClass::turnOff() {
  digitalWrite(_pin, LOW);
  LOG_D("Laser emitter has been turned <OFF>.");
}

LaserEmitterClass LaserEmitter;
