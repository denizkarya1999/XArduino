#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define RED 9
#define GREEN 10
#define BLUE 11

int bitTime = 500;

void allOff() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Transmission...");
}

void loop() {
  // START = RED
  allOff();
  digitalWrite(RED, HIGH);
  delay(bitTime);

  // DATA = 01010 using GREEN
  // 0 = OFF
  allOff();
  delay(bitTime);

  // 1 = GREEN
  allOff();
  digitalWrite(GREEN, HIGH);
  delay(bitTime);

  // 0 = OFF
  allOff();
  delay(bitTime);

  // 1 = GREEN
  allOff();
  digitalWrite(GREEN, HIGH);
  delay(bitTime);

  // 0 = OFF
  allOff();
  delay(bitTime);

  // END = BLUE
  allOff();
  digitalWrite(BLUE, HIGH);
  delay(bitTime);

  // pause
  allOff();
  delay(1500);
}