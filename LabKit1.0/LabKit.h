#ifndef _LABKIT_H_
#define _LABKIT_H_
/* Uses HARDWARE Serial AND SoftwareSerial for DEBUG
HardwareSerial * Serial;
Serial->print("AT");
ifdef DEBUG
SoftwareSerial * Serial;
Serial->print("AT");
*/
class HardwareSerial;
#ifdef DEBUG
class SoftwareSerial;
#endif
#include <Arduino.h>
#include <WiFi.h>
// #include "Serial.h"
class LabKit
{

public :

      //  void printWifiStatus(void);
        void printWifiStatus();
        void Timer(int sec,int min ,int hr);
        void StreamData(void);
        void LCD_DISPLAY(void);
        void Led_Blink(int _TIME);


private :

};
#endif
class ESP_WIFI_MODULE
{

      public:
        void Innitialize(String _myKit);
        void ConnectWifi(void);

      private:
};
