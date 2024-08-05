int data = 0;
#include <Stepper.h>
const int positive = 200;
const int negative = -200;

Stepper myStepper(positive,negative,8,9,10,11);
int stepCount = 0;

void setup(){
  myStepper.setSpeed(60);
  Serial.begin(9600);

}

void loop(){
  while(Serial.available()){
    data = Serial.read();
  }

  if(data == '1'){
    if(stepCount == 0){
      Serial.print("UP");
      Serial.print("\n");
      myStepper.step(positive);
      stepCount++;
    }
    delay(500);
  }
  else if (data == '0'){
    if(stepCount == 1){
      Serial.print("DOWN");
      Serial.print("\n");
      myStepper.step(negative);
      stepCount--;
    }
    delay(500);
  }

}