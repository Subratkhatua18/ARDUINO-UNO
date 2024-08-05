int myvalue=0;
void setup() {
  Serial.begin(9600);

}

void loop() {
myvalue=random(1,7);
Serial.print("The Dice number is: ");
Serial.println(myvalue);
delay(500);

}
