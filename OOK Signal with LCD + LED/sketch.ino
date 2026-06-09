#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LED_PIN 13

int bitTime = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Transmission...");
}

void loop() {
  // Send OOK message: 01010
  // 0 = LED OFF
  // 1 = LED ON

  digitalWrite(LED_PIN, LOW);   // 0
  delay(bitTime);

  digitalWrite(LED_PIN, HIGH);  // 1
  delay(bitTime);

  digitalWrite(LED_PIN, LOW);   // 0
  delay(bitTime);

  digitalWrite(LED_PIN, HIGH);  // 1
  delay(bitTime);

  digitalWrite(LED_PIN, LOW);   // 0
  delay(bitTime);

  // pause before repeating
  delay(1500);
}