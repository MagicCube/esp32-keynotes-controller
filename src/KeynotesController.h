#pragma once

#include <Arduino.h>

/**
 *  Represents a keynotes controller.
 *  The class has a global singleton which named `KeynotesController`.
 */
class KeynotesControllerClass {
public:
  // Creates a new instance of `KeynotesControllerClass`.
  KeynotesControllerClass();

  // Sends 'Next Slide' command to remote.
  void nextSlide();

  // Sends 'Previous Slide' command to remote.
  void previousSlide();

private:
};

extern KeynotesControllerClass KeynotesController;
