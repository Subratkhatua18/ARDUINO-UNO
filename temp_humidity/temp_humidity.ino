#include <dht.h>
#define outpin 10
#define LED_PIN 9
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
  float temp = DHT.temperature;
  Serial.print("Temperature in celcius: ");
  Serial.print(temp);
  Serial.println("C");
  Serial.print("Temperature in fahrenheit : ");
  Serial.print((temp*9/5)+32);
  Serial.println("F");
  delay(800);

  if(temp>=29.00){
     digitalWrite(LED_PIN,HIGH);
  delay(50);
  }
  else{
     digitalWrite(LED_PIN,LOW);
  delay(50);
  }
}