#include <map>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

#define BT_DISCOVER_TIME 10000
esp_spp_sec_t sec_mask = ESP_SPP_SEC_NONE; 
esp_spp_role_t role = ESP_SPP_ROLE_SLAVE;  

void setup() {
  Serial.begin(115200);
  if (!SerialBT.begin("ESP32test", true)) {
    Serial.println("========== serialBT failed!");
    abort();
  }
  Serial.println("Starting discoverAsync...");
  BTScanResults *btDeviceList = SerialBT.getScanResults();  
  if (SerialBT.discoverAsync([](BTAdvertisedDevice *pDevice) {
        Serial.printf(">>>>>>>>>>>Found a new device asynchronously: %s\n", pDevice->toString().c_str());
      })) {
    delay(BT_DISCOVER_TIME);
    Serial.print("Stopping discoverAsync... ");
    SerialBT.discoverAsyncStop();
    Serial.println("discoverAsync stopped");
    delay(5000);
    if (btDeviceList->getCount() > 0) {
      BTAddress addr;
      int channel = 0;
      Serial.println("Found devices:");
      for (int i = 0; i < btDeviceList->getCount(); i++) {
        BTAdvertisedDevice *device = btDeviceList->getDevice(i);
        Serial.printf(" ----- %s  %s %d\n", device->getAddress().toString().c_str(), device->getName().c_str(), device->getRSSI());
        std::map<int, std::string> channels = SerialBT.getChannels(device->getAddress());
        Serial.printf("scanned for services, found %d\n", channels.size());
        for (auto const &entry : channels) {
          Serial.printf("     channel %d (%s)\n", entry.first, entry.second.c_str());
        }
        if (channels.size() > 0) {
          addr = device->getAddress();
          channel = channels.begin()->first;
        }
      }
      if (addr) {
        Serial.printf("connecting to %s - %d\n", addr.toString().c_str(), channel);
        SerialBT.connect(addr, channel, sec_mask, role);
      }
    } else {
      Serial.println("Didn't find any devices");
    }
  } else {
    Serial.println("Error on discoverAsync f.e. not workin after a \"connect\"");
  }
}

String sendData = "Hi from esp32!\n";

void loop() {
  if (!SerialBT.isClosed() && SerialBT.connected()) {
    if (SerialBT.write((const uint8_t *)sendData.c_str(), sendData.length()) != sendData.length()) {
      Serial.println("tx: error");
    } else {
      Serial.printf("tx: %s", sendData.c_str());
    }
    if (SerialBT.available()) {
      Serial.print("rx: ");
      while (SerialBT.available()) {
        int c = SerialBT.read();
        if (c >= 0) {
          Serial.print((char)c);
        }
      }
      Serial.println();
    }
  } else {
    Serial.println("not connected");
  }
  delay(1000);
}
