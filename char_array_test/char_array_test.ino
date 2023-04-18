void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  String myString = "10101010";
  byte buffer[myString.length() + 1];

  myString.toCharArray(buffer, myString.length() + 1);

  for (int i = 0; i < myString.length() + 1; i++){
    Serial.println(buffer[i]);
    if (buffer[i] == 48){
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if (buffer[i] == 49){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    delay(1000);
  }
}

void loop() {
}
