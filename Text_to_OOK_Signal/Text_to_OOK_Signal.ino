const int ledPin = 13;

const int bitPeriodUs = 166;   // 6000 Hz
const int pulseWidthUs = 80;   // ON time for bit 1

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  sendTextOOK("X27", 40);
  delay(10);
}

void sendTextOOK(const char* text, int repeatCount) {
  for (int r = 0; r < repeatCount; r++) {
    for (int i = 0; text[i] != '\0'; i++) {
      sendByteOOK(text[i]);
    }
  }

  digitalWrite(ledPin, LOW);
}

void sendByteOOK(char c) {
  // Send 8 bits, MSB first
  for (int bit = 7; bit >= 0; bit--) {
    if ((c >> bit) & 1) {
      sendOne();
    } else {
      sendZero();
    }
  }
}

void sendOne() {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(pulseWidthUs);

  digitalWrite(ledPin, LOW);
  delayMicroseconds(bitPeriodUs - pulseWidthUs);
}

void sendZero() {
  digitalWrite(ledPin, LOW);
  delayMicroseconds(bitPeriodUs);
}
