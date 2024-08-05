int red = 13;
int blue = 12;
int green = 11;

int arr[]={red,green,blue};
void setup() {
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop(){
  for(int i=0;i<=3;i++){
    for(int value=0;value<=255;value++){
      analogWrite(arr[i],value);
      delay(10);
    }
    delay(10);

    for(int value=255;value>=0;value--){
      analogWrite(arr[i],value);
      delay(10);
    }
    delay(10);
  }
}