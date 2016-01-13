/******************************************************************************

Labkit Library is an a open source library for streaming data online to Labkit web
Sever
*             .-.._
*       __  /`     '.
*    .-'  `/   (   a \
*   /      (    \,_   \
*  /|       '---` |\ =|            *------- * ^ X
* ` \    /__.-/  /  | |            |_ _ _ _ |
*    |  / / \ \  \   \_\           *
*    |__|_|  |_|__\                |_ _ _ _
*    |__|_|  |_|__\
*
*   Author : Bob Raphtone Afwata
*   Company  :Sharpbrains.
*   Date    :10TH Jan 2016
*******************************************************************************/
#include "Arduino.h"
# include "Labkit.h"
# define LED 13
# define  _0N_STATUS HIGH
# define  _0FF_STATUS LOW
# define DEBUG
# define  ACCESS_POINT_NAME access_point_name
# define  ACCESS_POINT_PASSWORD password

#include <WiFi.h>
//char ssid[] = "yourNetwork";     //  your network SSID (name)
//char pass[] = "secretPassword";

//# include <WiFi.h>

//Connect the ESP 8266 to the Internet and Print Wifi Status to  Nokia LCD
void ESP_WIFI_MODULE::Innitialize()
{
 serial->begin(baud);
 serial->println(F("AT"));
if (! check_esp_response(1000, F("OK"))) {
   debug("Error AT");
   return;
    }
  begun = true;
}
void LabKit::LCD_DISPLAY(void)
     {

     Serial.println("It Works perfectly");

    }

void LabKit::StreamData(void){

}
void LabKit::Led_Blink(int _TIME){
  digitalWrite(LED, _0N_STATUS);   // turn the LED on (HIGH is the voltage level)
  delay(_TIME);              // wait for a second
  digitalWrite(LED,  _0FF_STATUS);    // turn the LED off by making the voltage LOW
  delay(_TIME);
}
void LabKit::Timer(int sec,int min, int hr){

 //int sec,min,hr;
 for (sec=0;sec<=60;sec++)
     {
       min=+1;
     }
  for (min=0;min<=60;min++)
         {
           hr=+1;
         }
       sec++;
        // return(sec);
         Serial.print(" The Time is :");
          Serial.println();

}
void ESP_WIFI_MODULE::ConnectWifi()
     {
       if (! begun) {
  begin();
}

// 1 = client
serial->println(F("AT+CWMODE=1"));

if (! check_esp_response(1000, F("OK"))) {
  debug("Error AT+CWMODE");
  return false;
}

if (! reset()) {
       debug("Error reset() in connect()");
     return false;
   }

   serial->println(F("AT+CWJAP?"));

   if (! check_esp_response(1000, ssid)) {
     serial->print(F("AT+CWJAP=\""));
     serial->print(ssid);
     serial->print(F("\",\""));
     serial->print(password);
     serial->println(F("\""));

     if (! check_esp_response(5000, F("OK"))) {
       debug("Error AT+CWJAP");
       return false;
     }
   }

   return true;
 }

}
