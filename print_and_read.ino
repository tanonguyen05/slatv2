String incomingByte ;
int EMGPin1 = A0;
    
int output1[40] = {};

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
  incomingByte = Serial.readStringUntil('\n');
    if (incomingByte == "on") {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.write("Led on");
    }
    else if (incomingByte == "off") {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.write("Led off");
    }
    else{
      Serial.write("invald input");
    }
  }
}
