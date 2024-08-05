#include <dht.h>
#define outpin 10
dht DHT;
void setup(){
  Serial.begin(9600);
}
void loop(){
  int readData = DHT.read11(outpin);
  float temp = DHT.temperature;
  Serial.print("Temperature in celcius: ")
  Serial.print(temp)
  Serial.println("C")
  Serial.print("Temperature in fahrenheit : ");
  Serial.print((temp*9/5)+32);
  Serial.println("F");
  delay(800);
}