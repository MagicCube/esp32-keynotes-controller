#include "BLEKeyboard.h"

#include "conf.h"

BLEKeyboardClass::BLEKeyboardClass() {
}

void BLEKeyboardClass::begin() {
  _server = BLEDevice::createServer();
  _hid = new BLEHIDDevice(_server);

  // Input / Output
  _inputCharacteristic = _hid->inputReport(1);
  _setAccessPermission(_inputCharacteristic);
  auto outputCharacteristic = _hid->outputReport(1);
  _setAccessPermission(outputCharacteristic);

  // Add encryption to built-in characteristics and descirptors.
  _setAccessPermission(_hid->deviceInfo(), 0x2a50);
  _hid->pnp(0x02, 0xe502, 0xa111, 0x0210);
  _setAccessPermission(_hid->hidService(), 0x2a4a);
  _hid->hidInfo(0x00, 0x01);
  _setAccessPermission(_hid->hidService(), 0x2a4b);
  _setAccessPermission(_hid->hidService(), 0x2a4c);
  _setAccessPermission(_hid->hidService(), 0x2a4e);
  _setAccessPermission(_hid->batteryService(), 0x2a19);

  // Set battery level
  _hid->setBatteryLevel(100);

  // Send HID report
  _hid->reportMap((uint8_t *)KEYBOARD_REPORT_MAP, sizeof(KEYBOARD_REPORT_MAP));

  // Disable Security
  BLESecurity *security = new BLESecurity();
  security->setCapability(ESP_IO_CAP_NONE);

  // Start HID service
  _hid->startServices();
}

void BLEKeyboardClass::startAdvertising() {
  BLEAdvertising *advertising = _server->getAdvertising();
  advertising->setAppearance(HID_KEYBOARD);
  advertising->addServiceUUID(_hid->hidService()->getUUID());
  advertising->start();
  _server->startAdvertising();
}

void BLEKeyboardClass::stopAdvertising() {
  BLEAdvertising *advertising = _server->getAdvertising();
  advertising->stop();
}

void BLEKeyboardClass::pressKey(uint8_t keyCode) {
  uint8_t report[] = {0x0, 0x0, 0x51, 0x0, 0x0, 0x0, 0x0, 0x0};
  _inputCharacteristic->setValue(report, sizeof(report));
  _inputCharacteristic->notify();
}

void BLEKeyboardClass::releaseAll() {
  uint8_t report[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
  _inputCharacteristic->setValue(report, sizeof(report));
  _inputCharacteristic->notify();
}

void BLEKeyboardClass::_setAccessPermission(BLECharacteristic *characteristic) {
  characteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENCRYPTED |
                                       ESP_GATT_PERM_WRITE_ENCRYPTED);

  auto desc = characteristic->getDescriptorByUUID(BLEUUID((uint16_t)0x2904));
  if (desc) {
    desc->setAccessPermissions(ESP_GATT_PERM_READ_ENCRYPTED | ESP_GATT_PERM_WRITE_ENCRYPTED);
  }

  desc = characteristic->getDescriptorByUUID(BLEUUID((uint16_t)0x2908));
  if (desc) {
    desc->setAccessPermissions(ESP_GATT_PERM_READ_ENCRYPTED | ESP_GATT_PERM_WRITE_ENCRYPTED);
  }

  desc = characteristic->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
  if (desc) {
    desc->setAccessPermissions(ESP_GATT_PERM_READ_ENCRYPTED | ESP_GATT_PERM_WRITE_ENCRYPTED);
  }
}

void BLEKeyboardClass::_setAccessPermission(BLEService *service, uint16_t uuid) {
  _setAccessPermission(service->getCharacteristic(BLEUUID(uuid)));
}

BLEKeyboardClass BLEKeyboard;
