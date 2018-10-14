#pragma once

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEHIDDevice.h>

/**
 * Represents a virtual Bluetooth keyboard.
 */
class BLEKeyboardClass : public BLEServerCallbacks {
public:
  // Creates a new instance of `BLEKeyboardClass`.
  BLEKeyboardClass();

  // Initializes the BLE HID server.
  void begin();

  // Returns a boolean that indicates whether the Keyboard has been connected.
  bool isConnected();

  // Starts BLE advertising.
  void startAdvertising();

  // Stops BLE advertising.
  void stopAdvertising();

  // Simulates pressing the specific key.
  void pressKey(uint8_t keyCode);

  // Simulates releasing all the pressed keys.
  void releaseAll();

  // Simulates pressing and releasing the specific key.
  void strokeKey(uint8_t keyCode);

  // Implements BLEServerCallbacks interface
  void onConnect(BLEServer *server);
  void onDisconnect(BLEServer *server);

private:
  void _setAccessPermission(BLECharacteristic *characteristic);
  void _setAccessPermission(BLEService *service, uint16_t uuid);

  bool _connected;
  BLEServer *_server;
  BLEHIDDevice *_hid;
  BLECharacteristic *_inputCharacteristic;
};

extern BLEKeyboardClass BLEKeyboard;
