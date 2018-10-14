#include <Arduino.h>

#include <BLEDevice.h>
#include <soc/rtc_cntl_reg.h>
#include <soc/soc.h>

#include "conf.h"
#include "log.h"

#include "BLEKeyboard.h"
#include "Button.h"
#include "KeynotesController.h"
#include "LaserLight.h"

Button previousSlideButton(PREVIOUS_SLIDE_BUTTON_PIN);
Button nextSlideButton(NEXT_SLIDE_BUTTON_PIN);
Button laserButton(LASER_BUTTON_PIN);
LaserLight laserLight(LASER_LIGHT_PIN);

int eventCounter = 0;

void setup() {
  // Disable brownout detector
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  Serial.begin(115200);
  Serial.println();

  LOG_I("KeyLight - An ESP32 based BLE Keynote remote controller.");
  LOG_I("Designed by Henry Li <henry1943@163.com>.");
  LOG_I("Copyright %d. All rights reserved.", 2018);

  // Initialize buttons and laser emitter.
  previousSlideButton.onPress([]() {
    LOG_D("<<");
    KeynotesController.previousSlide();
  });
  previousSlideButton.begin();
  nextSlideButton.onPress([]() {
    LOG_D(">>");
    KeynotesController.nextSlide();
  });
  nextSlideButton.begin();
  laserButton.onPress([]() { laserLight.turnOn(); });
  laserButton.onRelease([]() { laserLight.turnOff(); });
  laserButton.begin();
  laserLight.begin();

  LOG_I("Initializing BLE Device '%s'...", DEVICE_NAME);
  BLEDevice::init(DEVICE_NAME);
  LOG_I("Initializing BLE HID services...");
  BLEKeyboard.begin();

  BLEKeyboard.startAdvertising();

  LOG_I("Initialization has been <DONE>.");
}

void updateButtons() {
  previousSlideButton.update();
  nextSlideButton.update();
  laserButton.update();
}

void loop() {
  updateButtons();
}
