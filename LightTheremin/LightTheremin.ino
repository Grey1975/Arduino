int senseVal;
int senseLow = 1023;
int senseHigh = 0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    senseVal = analogRead(A0);
    if (senseVal > senseHigh) {
      senseHigh = senseVal;
    }
    if (senseVal < senseLow) {
      senseLow = senseVal;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  senseVal = analogRead(A0);
  int pitch = map(senseVal, senseLow, senseHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
