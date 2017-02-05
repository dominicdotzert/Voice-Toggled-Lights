#include <Servo.h>

const int servoPin = 9;
const int inputPin = 2;
boolean lightStatus = false;
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(82);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    toggle();
    delay(1000);
  }
}

void toggle() {
  if (lightStatus) { 
    servo.write(53);
    delay(100);
    servo.write(82);
    lightStatus = false;
  } else {
    servo.write(108);
    delay(100);
    servo.write(82);
    lightStatus = true;
  }
}
