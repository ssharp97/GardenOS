String command;
int r1=13;


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  pinMode(r1, OUTPUT);
  
  delay(2000);

  Serial.println("Ready...");
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("[0, 0, 0, 0, 0, 0, 0, 0]")) {
      digitalWrite(r1, HIGH);
    }

    else if (command.equals("[0, 0, 0, 0, 0, 0, 0, 0]")) {
      digitalWrite(r1, LOW);
    }
    
    else {
      Serial.println("bad command");
    }
    Serial.print("Command: ");
    Serial.println(command);
  }
}
