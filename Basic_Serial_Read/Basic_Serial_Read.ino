String info;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    info = Serial.read();
    
    Serial.print("Received: ");
    Serial.println(info); 
  }
  else {
    Serial.println("No Serial Devices Available...");
  }
  delay(1000);
}
