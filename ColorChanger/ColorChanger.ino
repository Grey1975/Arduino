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
  // read sensor values
  redSnsVal = analogRead(redSns);
  delay(5);
  grnSnsVal = analogRead(grnSns);
  delay(5);
  bluSnsVal = analogRead(bluSns);

  // log raw sensor input to terminal
  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSnsVal);
  Serial.print("\t green: ");
  Serial.print(grnSnsVal);
  Serial.print("\t blue: ");
  Serial.println(bluSnsVal);

  // adjusted values
  red = redSnsVal / 4;
  grn = grnSnsVal / 4;
  blu = bluSnsVal / 4;

  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(red);
  Serial.print("\t green: ");
  Serial.print(grn);
  Serial.print("\t blue: ");
  Serial.println(blu);

  analogWrite(redLED, red);
  analogWrite(grnLED, grn);
  analogWrite(bluLED, blu);
}
