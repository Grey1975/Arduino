// Global Variables
const int grnLED = 9;
const int redLED = 10;
const int bluLED = 11;
const int grnSns = A1;
const int redSns = A0;
const int bluSns = A2;
int red = 0;
int grn = 0;
int blu = 0;
int redSnsVal = 0;
int grnSnsVal = 0;
int bluSnsVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(grnLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(bluLED, OUTPUT);
}

void loop() {
  redSnsVal = analogRead(redSns);
  delay(5);
  grnSnsVal = analogRead(grnSns);
  delay(5);
  bluSnsVal = analogRead(bluSns);
  delay(5);
}
