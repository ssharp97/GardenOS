String command;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);


  delay(2000);

  Serial.println("Ready...");
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("on")) {
      digitalWrite(LED_BUILTIN, HIGH);
    }

    else if (command.equals("off")) {
      digitalWrite(LED_BUILTIN, LOW);
    }
    
    else {
      Serial.println("bad command");
    }
    Serial.print("Command: ");
    Serial.println(command);
  }
}
