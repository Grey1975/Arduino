const int cp1 = 2;
const int cp2 = 3;
const int enPin = 9;
const int dirSwitchPin = 4;
const int onOffStatePin = 5;
const int potPin = A0;
int onOffState = 0;
int prevOnOffState = 0;
int dirSwitchState = 0;
int prevDirSwitchState = 0;
int motorEnable = 0;
int motorSpeed = 0;
int motorDir = 1;

void setup() {
  pinMode(dirSwitchPin, INPUT);
  pinMode(onOffStatePin, INPUT);
  pinMode(cp1, OUTPUT);
  pinMode(cp2, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
}

void loop() {
  onOffState = digitalRead(onOffStatePin);
  delay(1);
  dirSwitchState = digitalRead(dirSwitchPin);
  motorSpeed = analogRead(potPin) / 4;

  if (onOffState != prevOnOffState) {
    if (onOffState == HIGH) {
      motorEnable = !motorEnable;
    }
  }

  if (dirSwitchState != prevDirSwitchState) {
    if (dirSwitchState == HIGH) {
      motorDir = !motorDir;
    }
  }

  if (motorDir == 1) {
    digitalWrite(cp1, HIGH);
    digitalWrite(cp2, LOW);
  } else {
    digitalWrite(cp1, LOW);
    digitalWrite(cp2, HIGH);
  }

  if (motorEnable == 1) {
    analogWrite(enPin, motorSpeed);
  } else {
    analogWrite(enPin, 0);
  }

  prevDirSwitchState = dirSwitchState;
  prevOnOffState = onOffState;
}
