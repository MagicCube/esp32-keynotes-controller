#pragma once

#include <Arduino.h>

/**
 * Represents a laser emitter module.
 * The class has a global singleton which named `LaserLight`.
 *
 * https://item.taobao.com/item.htm?spm=a1z09.2.0.0.76d12e8dVNq61T&id=522576364570&_u=e10f2tidee6
 */
class LaserLight {
public:
  // Creates a new instance of `LaserLight`.
  LaserLight(uint8_t pin);

  // Initializes the laser emitter.
  void begin();

  // Turns on/off the laser.
  void turnOn();
  void turnOff();

private:
  bool _on = false;
  uint8_t _pin;
};
