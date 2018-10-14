#include "KeynotesController.h"

#include "conf.h"

#include "BLEKeyboard.h"

KeynotesControllerClass::KeynotesControllerClass() {
}

void KeynotesControllerClass::nextSlide() {
  BLEKeyboard.pressKey(KEY_CODE_NEXT_SLIDE);
  BLEKeyboard.releaseAll();
}

void KeynotesControllerClass::previousSlide() {
  BLEKeyboard.pressKey(KEY_CODE_NEXT_SLIDE);
  BLEKeyboard.releaseAll();
}

KeynotesControllerClass KeynotesController;
