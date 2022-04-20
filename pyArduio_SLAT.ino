String incomingByte ;
int EMGPin1 = A0;
int EMGPin2 = A1;
int EMGPin3 = A2;
int EMGPin4 = A3;
    
int output1[40] = {};
int output2[40] = {};
int output3[40] = {};
int output4[40] = {};

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
  incomingByte = Serial.readStringUntil('\n');
    if (incomingByte == "yes") {
      for(int  i = 0; i < 40; i++){
        output1[i] = analogRead(A0);
        output2[i] = analogRead(A1);
        output3[i] = analogRead(A2);
        output4[i] = analogRead(A3);
        delay(50);
      }
      for (int i = 0; i < 40; i++){
        Serial.write(output1[i]);
        Serial.write(output2[i]);
        Serial.write(output3[i]);
        Serial.write(output4[i]);
      }
    }
    else{
      Serial.write("invald input");
    }
  }
}
