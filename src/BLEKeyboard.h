#pragma once

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEHIDDevice.h>

/**
 * Represents a virtual Bluetooth keyboard.
 */
class BLEKeyboardClass {
public:
  // Creates a new instance of `BLEKeyboardClass`.
  BLEKeyboardClass();

  // Initializes the BLE HID server.
  void begin();

  // Start BLE advertising.
  void startAdvertising();

  // Stop BLE advertising.
  void stopAdvertising();

private:
  void _setAccessPermission(BLECharacteristic *characteristic);
  void _setAccessPermission(BLEService *service, uint16_t uuid);

  BLEServer *_server;
  BLEHIDDevice *_hid;
  BLECharacteristic *_inputCharacteristic;
};

extern BLEKeyboardClass BLEKeyboard;
