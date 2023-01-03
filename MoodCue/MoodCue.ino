#include <Servo.h>

Servo myServo;
const int potPin = A0;
int potVal;
int angle;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potval: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
