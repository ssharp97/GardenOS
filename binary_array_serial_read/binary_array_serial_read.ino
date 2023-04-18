// Valid input data from serial is 8 chars followed by a newline.
// 10001001
const int dataSize = 8;
const byte bufferSize = 9;
char inputBuffer[bufferSize + 1];
int r1=13;

void setup(){
  Serial.begin(9600);
  pinMode(r1, OUTPUT);

}

void loop(){

  if(Serial.available() > 0){
    byte bytesRead = Serial.readBytesUntil('\n', inputBuffer, bufferSize);
    if(bytesRead == dataSize){
      for(byte i = 0; i < dataSize; i++){
        if(inputBuffer[i] == '1'){
          Serial.print("on ");
          digitalWrite(r1, HIGH);
        }
        else{
          Serial.print("b'\x01\x01\x01\x01\x01\x01\x01\x01'");
          digitalWrite(r1, LOW);
        }
      }
      Serial.println();
    }
    else{
      Serial.println("Invalid data length.");
    }
  }
}
