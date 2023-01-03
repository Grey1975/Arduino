// global vars
const int sensorPin = A0;
const float baseTemp = 21.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 2; i < 5; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Degrees C: ");
  float temp = (voltage - 0.5) * 100.0;
  Serial.println(temp);

  if (temp < baseTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= baseTemp + 2 && temp < baseTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= baseTemp + 4 && temp < baseTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temp >= baseTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
