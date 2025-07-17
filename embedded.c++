String inputString = "";
bool stringComplete = false;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Type ON or OFF to control the LED");
  inputString.reserve(50);
}

void loop() {
  if (stringComplete) {
    inputString.trim();
    Serial.print("Received command: ");
    Serial.println(inputString);

    if (inputString.equalsIgnoreCase("ON")) {
      digitalWrite(13, HIGH);
      Serial.println("LED turned ON");
    } else if (inputString.equalsIgnoreCase("OFF")) {
      digitalWrite(13, LOW);
      Serial.println("LED turned OFF");
    } else {
      Serial.println("Invalid command. Type ON or OFF.");
    }

    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}