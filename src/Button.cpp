#include "Button.h"

Button::Button(uint8_t pin) {
  _pin = pin;
}

void Button::begin() {
  pinMode(_pin, INPUT_PULLUP);
}

void Button::onPress(EventHandler handler) {
  _pressEventHandler = handler;
}

void Button::onRelease(EventHandler handler) {
  _releaseEventHandler = handler;
}

void Button::update() {
  auto value = digitalRead(_pin);
  if (!_pressing) {
    if (value == LOW && millis() - _lastPress > 300) {
      _pressing = true;
      _lastPress = millis();
      _firePressEvent();
    }
  } else {
    if (value == HIGH) {
      _pressing = false;
      _lastPress = millis();
      _fireReleaseEvent();
    }
  }
}

void Button::_firePressEvent() {
  if (_pressEventHandler) {
    _pressEventHandler();
  }
}

void Button::_fireReleaseEvent() {
  if (_releaseEventHandler) {
    _releaseEventHandler();
  }
}
