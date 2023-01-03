int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState=digitalRead(2);
//////////////////////////////////////////////////////////////////////////////////////
  switch(switchState) {
    case HIGH:
      Serial.print("Switch went High.\n");
      for(int i = 0; i < 4; ++i) {
        int foo = random(3,7);
        digitalWrite(foo, HIGH);
        delay(400);
        digitalWrite(foo, LOW);
        delay(400);
      }
    case LOW:
      break;
  }
}

int randomLed() {
  
}
