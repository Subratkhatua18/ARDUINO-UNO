#include <Stepper.h>

const int positive = 200;
const int negative = -200;
const int irPin = 12; 

Stepper myStepper(positive,negative, 8, 9, 10, 11);

void setup() {
  pinMode(irPin, INPUT); 
  myStepper.setSpeed(60); 
}

void loop() {
  if (digitalRead(irPin) == HIGH) { 
   
    myStepper.step(positive);
    delay(500); 
    
  } else{

    myStepper.step(negative);
    delay(500);
  }
}
