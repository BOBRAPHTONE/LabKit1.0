

#include <LTask.h>
#include <LWiFi.h>
#include <LWiFiClient.h>
#include <LBattery.h>

#define WIFI_AP "Abriles_LTE"
#define WIFI_PASSWORD "12345678"
#define WIFI_AUTH LWIFI_WPA  // choose from LWIFI_OPEN, LWIFI_WPA, or LWIFI_WEP.

// Ubidots information

#define URL        "things.ubidots.com"
#define TOKEN      "6ZImxxxxxxxtlSnMd8ayOpjRps"          // replace with your Ubidots token generated in your profile tab
#define VARIABLEID "5576280e76254212a7d0ece9"

int counter = 0;

void setup()
{
  LTask.begin();
  LWiFi.begin();
  Serial.begin(9600);

  // keep retrying until connected to AP
  Serial.println("Connecting to AP");
  while (0 == LWiFi.connect(WIFI_AP, LWiFiLoginInfo(WIFI_AUTH, WIFI_PASSWORD)))
  {
    delay(1000);
  }
}

void loop()
{
  save_value(String(analogRead(A0)));
  //delay(500);
}

void save_value(String value){

  Serial.println("Sending value to Ubidots...");
  LWiFiClient c;
  while (!c.connect(URL, 80))
  {
    Serial.println("Retrying to connect...");
    delay(100);
  }

  String data = "{\"value\":"+ value + "}";
  String thisLength = String(data.length());

  // Build HTTP POST request
  c.print("POST /api/v1.6/variables/");
  c.print(VARIABLEID);
  c.print("/values?token=");
  c.print(TOKEN);
  c.println(" HTTP/1.1");
  c.println("Content-Type: application/json");
  c.println("Content-Length: " + thisLength);
  c.print("Host: ");
  c.println(URL);
  c.print("\n" + data);
  c.print(char(26));

  // read server response

  while (c){
    Serial.print((char)c.read());}

  c.stop();

}
