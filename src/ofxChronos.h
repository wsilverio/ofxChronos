#ifndef OFX_CHRONOS_H
#define OFX_CHRONOS_H

#include "ofMain.h"

class ofxChronos : public ofThread
{

public:
    ofxChronos();
    ofxChronos(std::string portName);
    ofxChronos(std::string portName, unsigned int baudrate);

    void start();
    void start(bool threadLoop);
    void stop();
    
    void dataRequest(byte data);
    void dataRead();

    void resetData();

    bool R1; // top right button
    bool L1; // top left button
    bool L2; // bottom left button

    // accelerometer data
    int accX;
    int accY;
    int accZ;

    bool waiting;

private:
    ofSerial Chronos;

    bool time_to_exit;
    uint8_t startAccessPoint[3] = {255, 7, 3};
    uint8_t accDataRequest[7] = {255, 8, 7, 0, 0, 0, 0};

};

#endif // OFX_EZ430CHRONOS_H