#include "LaserEmitter.h"

#include "log.h"

LaserEmitter::LaserEmitter(uint8_t pin) {
  _pin = pin;
}

void LaserEmitter::begin() {
  pinMode(_pin, OUTPUT);
  turnOff();
}

void LaserEmitter::turnOn() {
  digitalWrite(_pin, HIGH);
  LOG_D("Laser emitter has been turned <ON>.");
}

void LaserEmitter::turnOff() {
  digitalWrite(_pin, LOW);
  LOG_D("Laser emitter has been turned <OFF>.");
}
