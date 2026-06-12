#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// RGB LED pins
#define RED   9
#define GREEN 10
#define BLUE  11

// OOK timing
const int bitPeriodUs = 166;   // 6000 Hz bit period
const int pulseWidthUs = 80;   // LED ON time for bit 1

// LCD address and size
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Set RGB LED pins as outputs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Start LCD
  lcd.init();
  lcd.backlight();

  // Show regular value on top
  lcd.setCursor(0, 0);
  lcd.print("Decimal: 10");

  // Show binary value on bottom
  lcd.setCursor(0, 1);
  lcd.print("Binary: 1010");
}

// Turn off all RGB LED colors
void allOff() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// Send bit 1 using selected LED color
void sendOne(int pin) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseWidthUs);

  digitalWrite(pin, LOW);
  delayMicroseconds(bitPeriodUs - pulseWidthUs);
}

// Send bit 0 by keeping LED off
void sendZero() {
  allOff();
  delayMicroseconds(bitPeriodUs);
}

void loop() {
  // Start bit: 1 using RED
  sendOne(RED);

  // Message bits: 1010 using GREEN
  sendOne(GREEN);  // 1
  sendZero();      // 0
  sendOne(GREEN);  // 1
  sendZero();      // 0

  // End bit: 1 using BLUE
  sendOne(BLUE);
}
