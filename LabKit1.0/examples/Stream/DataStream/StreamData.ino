#include <LabKit.h>
# define WIFISSID
# define WIFIPASS

LabKit myKit;

void setup() {
  Serial.begin(9600);
  myKit.Timer(0,6,2);
  myKit.Blink();
  
}

void loop() {
//myKit.Blink();

}
