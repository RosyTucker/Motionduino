int ledPin = 12;
int speakerPin = 11;
int motionInputPin = 3;

int _C = 956;
bool motion = false;

void setupPins() {
  pinMode(motionInputPin, INPUT);
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  pinMode(speakerPin, OUTPUT);
  digitalWrite(speakerPin, LOW);
}

void setup() {
    Serial.begin(9600);
    setupPins();
}

void playAlarm() {
  if(motion) {
     digitalWrite(speakerPin,HIGH);
     delayMicroseconds(_C);
     digitalWrite(speakerPin, LOW);
     delayMicroseconds(_C);
  }
}

void checkForMotion() {
  if(digitalRead(motionInputPin) == HIGH && !motion) {
    Serial.print("Motion\n");
    digitalWrite(ledPin, HIGH);
    motion = true;
  } else if(digitalRead(motionInputPin) == LOW && motion) {
    motion = false;
    Serial.print("All is calm\n");
    digitalWrite(ledPin, LOW);
  }
}

void loop() {
  playAlarm();
  checkForMotion();
  delay(150);
}
