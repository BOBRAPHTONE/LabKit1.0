#include <SPI.h>
#include <WiFi.h>
#define WIFI_SUCCESS 11
#define POST_SUCCESS 12
int status = WL_IDLE_STATUS;

/* WIFI NAME AND PASSWORD */

char ssid[] = " ";
char pass[] = " ";

// Data Variables to Stream

int temp = 0; // temperature variable
int hum = 0;  // humidity variable
String data = ""; // store data to be sent




WiFiClient client;

IPAddress server(52,16,210,77);  // numeric IP for Google (no DNS)

unsigned long lastConnectionTime = 0;
boolean lastConnection = false;
const unsigned long postingInterval = 10000; //delay between updates in milliseconds

void setup()

{
Serial.begin(9600);

pinMode(WIFI_SUCCESS, OUTPUT);
pinMode(POST_SUCCESS, OUTPUT);
if (WiFi.status() == WL_NO_SHIELD)
{
Serial.println("WiFi shield not present");

while(true);

}

String fv = WiFi.firmwareVersion();

if(fv != "1.1.0")
{

Serial.println("Please upgrade the firmware");

}

//attempt to connect to WiFi network:

while(status != WL_CONNECTED){

Serial.print("CONNECTING TO THE WIFI :");
Serial.println(ssid);

// connect to WPA/WPA2 network.
status = WiFi.begin(ssid, pass);

// wait 10 seconds for connection
delay(10000);

}

// print out WiFi status
printWifiStatus();
digitalWrite(WIFI_SUCCESS, HIGH);
}

void loop()
{
/Make sensor readings

hum = analogRead(A0);
temp = analogRead(A1);
if( !client.connected() && (millis() - lastConnectionTime > postingInterval)){
Serial.print("Humidity is: ");
Serial.println(hum);
Serial.print("Temperature is: ");
Serial.println(temp);
httpRequest(temp,hum);

}


}

void httpRequest(int temp, int hum){


String tempStr = String(temp);
String humStr = String(hum);


//Serial.println("Sending http request...");

if(status = client.connect(server,80))

Serial.print("Successfully connected to server!");

if(status)
{

  Serial.println("I'm posting to the table!");
  digitalWrite(postSuccess, HIGH);
String request = "GET /sensorPost.php?temperature=" + tempStr +"&humidity=" + humStr + " HTTP/1.1";

client.println(request);
client.println("Host: uvkke2358fbb.vkaruri.koding.io");
client.println("Connection: close");
client.println();

lastConnectionTime = millis();


}

else{
Serial.println("connection failed");

}

client.stop();
delay(1000);
digitalWrite(postSuccess, LOW);
}



void printWifiStatus(){

  // print SSID of connected network
Serial.print("SSID: ");
Serial.println(WiFi.SSID());

// print WiFi shield's IP address
IPAddress ip = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);

// print the received signal strength:

long rssi = WiFi.RSSI();
Serial.print("signal strength (RSSI):");
Serial.print(rssi);
Serial.println("dBm");

}
