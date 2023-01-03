const int switchPin = 8;
unsigned long prevTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 600000;

void setup() {
  for (int x = 2; x < 8; ++x) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, OUTPUT);
}

void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime > interval) {
    prevTime = curTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 7) {
    }
  }
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; ++x) {
      digitalWrite(x, LOW);
    }
    led = 2;
    prevTime = curTime;
  }
  prevSwitchState = switchState;
}
