#ifndef FlashSave_H
#define FlashSave_H

#include <Arduino.h>
#include <Preferences.h>

class FlashSave {
public:
    FlashSave();
    void saveRSSI(int RSSI[][10], int rp);
    void loadRSSI(int RSSI[][10], const int numRows);
    void clearRSSI(int RSSI[][10], const int numRows);
};
#endif
