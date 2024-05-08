#include "FlashSave.h"

FlashSave::FlashSave() {
    // Constructor (if needed)
}

void FlashSave::saveRSSI(int RSSI[][10], int rp) {
  Preferences preferences;
  preferences.begin("RSSISave", false);
  for (int j = 0; j < 10; ++j) {
    String key = String(rp) + "_" + String(j);
    int8_t value = RSSI[rp][j];
    preferences.putChar(key.c_str(), value);
  }
  preferences.end();
}

void FlashSave::loadRSSI(int RSSI[][10], const int numRows) {
    Preferences preferences;
    preferences.begin("RSSISave", true);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < 10; ++j) {
          String key = String(i) + "_" + String(j);
          RSSI[i][j] = preferences.getChar(key.c_str(), 12);
        }
    }
    preferences.end();
}

void FlashSave::clearRSSI(int RSSI[][10], int numRows) {
  Preferences preferences;
  preferences.begin("RSSISave", false);
  // Clear preferences for the current namespace
  preferences.clear();
  preferences.end();
}

/*
void FlashSave::saveRSSI(const int RSSI[][10], const int numRows) {
    Preferences preferences;
    preferences.begin("RSSISave", false);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < 10; ++j) {
          String key = "rssi_" + String(i) + "_" + String(j);
          int8_t value = RSSI[i][j];
          preferences.putChar(key.c_str(), value);
        }
    }
    preferences.end();
}
*/