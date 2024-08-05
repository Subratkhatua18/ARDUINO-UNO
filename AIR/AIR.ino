#define LED_PIN 9
#define IR_PIN 3
#define NEW_PIN 10

void setup() {
  pinMode(LED_PIN,OUTPUT);
  pinMode(IR_PIN,INPUT);
  Serial.begin(9600);

}

void loop() {
 if(digitalRead(IR_PIN)==LOW)
 {
  digitalWrite(LED_PIN,HIGH);
  delay(50);
 }
 else if(digitalRead(IR_PIN)==LOW)
 {

  digitalWrite(NEW_PIN,LOW);
  delay(50);
 }
  else 
 {

  digitalWrite(NEW_PIN,LOW);
  delay(50);
 }

}
