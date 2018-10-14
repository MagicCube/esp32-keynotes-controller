#include "KeynotesController.h"

#include "conf.h"
#include "log.h"

#include "BLEKeyboard.h"

KeynotesControllerClass::KeynotesControllerClass() {
}

void KeynotesControllerClass::nextSlide() {
  BLEKeyboard.strokeKey(KEY_CODE_NEXT_SLIDE);
  LOG_D("<< NEXT SLIDE >>");
}

void KeynotesControllerClass::previousSlide() {
  BLEKeyboard.strokeKey(KEY_CODE_NEXT_SLIDE);
  LOG_D("<< PREVIOUS SLIDE >>");
}

KeynotesControllerClass KeynotesController;
