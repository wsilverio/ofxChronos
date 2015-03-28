// http://oliversmith.io/technology/2010/02/06/receiving-ti-ez430-chronos-button-presses-in-processing-and-python/

#include "ofxChronos.h"

ofxChronos::
ofxChronos()
{
    waiting = false;
    time_to_exit = false;
    Chronos.setup(0, 115200);
}

ofxChronos::
ofxChronos(std::string portName)
{
    waiting = false;
    time_to_exit = false;
    Chronos.setup(portName, 115200);
}

ofxChronos::
ofxChronos(std::string portName, unsigned int baudrate)
{
    waiting = false;
    time_to_exit = false;
    Chronos.setup(portName, baudrate);
}

void
ofxChronos::
start()
{
    if(!Chronos.isInitialized()) return;

    Chronos.writeBytes(&startAccessPoint[0], 3);  
}

void
ofxChronos::
start(bool threadLoop)
{
    if(!Chronos.isInitialized()) return;

    Chronos.writeBytes(&startAccessPoint[0], 3);
    
    if (threadLoop)
    {
        
    }else{

    }
}

void
ofxChronos::
stop()
{
    if(!Chronos.isInitialized()) return;

    time_to_exit = true;

    if (threadLoop)
    {
        
    }else{

    }
}

void
ofxChronos::
dataRequest()
{
    if(!Chronos.isInitialized()) return;

    Chronos.writeBytes(&accDataRequest[0], 3);
}

void
ofxChronos::
dataRead()
{
    if(!Chronos.isInitialized()) return;

    resetData();

    waiting = true;
    
    int buffer[7];

    if (Chronos.available() > 7)
    {
        device.readBytes(buffer, 7);
        int result = Chronos.readBytes( &buffer[0], 7);

        if (result == OF_SERIAL_ERROR){}
        else if(result == OF_SERIAL_NO_DATA){}
        else{
            
            if(buffer[3] == 18){
                L1 = true;
            }
            else if(buffer[3] == 34){
                L2 = true;
            }
            else if(buffer[3] == 50){
                R1 = true;
            }
            else if(buffer[3] == 1)
            {
                accX = buffer[4];
                accY = buffer[5];
                accZ = buffer[6];
            }
            
        }
    }

    waiting = false;    
}

void
ofxChronos::
resetData()
{
    R1 = L1 = L2 = false;
    accX = accY = accZ = 0;
}