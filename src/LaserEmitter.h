#pragma once

#include <Arduino.h>

/**
 * Represents a laser emitter module.
 * The class has a global singleton which named `LaserEmitter`.
 *
 * https://item.taobao.com/item.htm?spm=a1z09.2.0.0.76d12e8dVNq61T&id=522576364570&_u=e10f2tidee6
 */
class LaserEmitterClass {
public:
  // Creates a new instance of `LaserEmitter`.
  LaserEmitterClass();

  // Initializes the laser emitter.
  void begin(uint8_t pin);

  // Turns on/off the laser.
  void turnOn();
  void turnOff();

private:
  uint8_t _pin;
};

extern LaserEmitterClass LaserEmitter;
