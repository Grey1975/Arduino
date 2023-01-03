// GLOBAL VARIABLES
//int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}  // void setup()

void loop() {
  switch (digitalRead(2)) {
    case LOW:
      break;
    case HIGH:
      int randSeed = random(1, 50);
      for (int i = 0; i < randSeed; ++i) {
        int pin = random(4, 8);
        digitalWrite(pin, HIGH);
        // if you have a speaker hooked up go ahead and use this
        // analogWrite(3, 10);
        delay(50);
        digitalWrite(pin, LOW);
        analogWrite(3, 0);
        delay(50);
      }
      break;
  }
  delay(1);
  sadf
}  // void loop()
