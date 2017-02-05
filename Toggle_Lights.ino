#include <Servo.h>

const int servoPin = 9;
const int inputPin = 2;
boolean lightStatus = false;
Servo servo;

const int basePos = 82;
const int offPos = 53;
const int onPos = 108;

void setup() {
  servo.attach(servoPin);
  servo.write(basePos);
  pinMode(inputPin, INPUT);
}

void loop() {
  if (digitalRead(inputPin) == HIGH) {
    toggle();
    delay(1000);
  }
}

void toggle() {
  if (lightStatus) { 
    servo.write(offPos);
    delay(100);
    servo.write(basePos);
    lightStatus = false;
  } else {
    servo.write(onPos);
    delay(100);
    servo.write(basePos);
    lightStatus = true;
  }
}
