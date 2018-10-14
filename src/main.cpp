#include <Arduino.h>

#include <BLEDevice.h>

#include "conf.h"
#include "log.h"

#include "BLEKeyboard.h"
#include "KeynotesController.h"
#include "LaserEmitter.h"

void setup() {
  Serial.begin(115200);
  Serial.println();

  LOG("KeyLight - An ESP32 based BLE Keynote remote controller.");
  LOG("Designed by Henry Li <henry1943@163.com>.");
  LOG("Copyright %d. All rights reserved.", 2018);

  LaserEmitter.begin(LASER_EMITTER_PIN);

  LOG("Initializing BLE Device as '%s'...", DEVICE_NAME);
  BLEDevice::init(DEVICE_NAME);
  LOG("Initializing BLE HID services...");
  BLEKeyboard.begin();

  LOG("Start BLE advertising...");
  BLEKeyboard.startAdvertising();

  LOG("Initialization has been done successfully.");
}

void loop() {
  delay(2000);
  KeynotesController.nextSlide();
}
