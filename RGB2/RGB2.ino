int redPin = 13;
int greenPin = 12;
int bluePin = 11;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
    colorChange(255, 0, 0);
    delay(500);

    colorChange(0, 255, 0);
    delay(500);

    colorChange(0, 0, 255);
    delay(500);

    colorChange(255, 255, 0);
    delay(500);

    colorChange(0, 255, 255);
    delay(500);

    colorChange(255, 0, 255);
    delay(500);  

}
void colorChange(int red, int green, int blue) {
    digitalWrite(redPin, red);
    digitalWrite(greenPin, green);
    digitalWrite(bluePin, blue);
}