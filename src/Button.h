#pragma once

#include <Arduino.h>

#include "events.h"

class Button {
public:
  Button(uint8_t pin);

  void onPress(EventHandler handler);
  void onRelease(EventHandler handler);

  void begin();
  void update();

private:
  void _firePressEvent();
  void _fireReleaseEvent();

  uint8_t _pin;
  bool _pressing = false;
  unsigned long _lastPress = 0;
  EventHandler _pressEventHandler = NULL;
  EventHandler _releaseEventHandler = NULL;
};
