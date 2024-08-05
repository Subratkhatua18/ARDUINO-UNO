#include <dht.h>
#define outpin 10
dht DHT;
void setup(){
  Serial.begin(9600);
}
void loop(){
  int readData = DHT.read11(outpin);
  float h = DHT.humidity;
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("%");
  delay(800);
}