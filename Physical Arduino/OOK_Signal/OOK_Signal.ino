#define LED_PIN 13

// 6000 Hz bit timing
const int bitPeriodUs = 166;

// LED ON time for bit 1
const int pulseWidthUs = 80;

void setup() {
  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // Start with LED OFF
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Send data: 10101
  sendOne();   // 1
  sendZero();  // 0
  sendOne();   // 1
  sendZero();  // 0
  sendOne();   // 1

  // Small pause before repeating
  delay(1);
}

void sendOne() {
  // Bit 1 = LED ON briefly, then OFF
  digitalWrite(LED_PIN, HIGH);
  delayMicroseconds(pulseWidthUs);

  digitalWrite(LED_PIN, LOW);
  delayMicroseconds(bitPeriodUs - pulseWidthUs);
}

void sendZero() {
  // Bit 0 = LED stays OFF
  digitalWrite(LED_PIN, LOW);
  delayMicroseconds(bitPeriodUs);
}
