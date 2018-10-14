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

  LOG_I("KeyLight - An ESP32 based BLE Keynote remote controller.");
  LOG_I("Designed by Henry Li <henry1943@163.com>.");
  LOG_I("Copyright %d. All rights reserved.", 2018);

  LaserEmitter.begin(LASER_EMITTER_PIN);

  LOG_I("Initializing BLE Device as '%s'...", DEVICE_NAME);
  BLEDevice::init(DEVICE_NAME);
  LOG_I("Initializing BLE HID services...");
  BLEKeyboard.begin();

  BLEKeyboard.startAdvertising();

  LOG_I("Initialization has been done successfully.");
}

void loop() {
}
