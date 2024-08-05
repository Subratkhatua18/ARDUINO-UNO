int red = 10;
int blue = 9;
int green = 8;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
}


void loop() {
   digitalWrite(red,HIGH);
   delay(500);
   digitalWrite(green,HIGH);
   delay(500);
   digitalWrite(blue,HIGH);
   delay(500);
  

}
