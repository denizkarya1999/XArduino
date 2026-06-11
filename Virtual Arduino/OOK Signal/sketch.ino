#define RED 9
#define GREEN 10
#define BLUE 11

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // START = RED
  digitalWrite(RED, HIGH);
  delay(300);
  digitalWrite(RED, LOW);
  delay(300);

  // DATA = 01010 using GREEN
  // 0
  digitalWrite(GREEN, LOW);
  delay(300);

  // 1
  digitalWrite(GREEN, HIGH);
  delay(300);

  // 0
  digitalWrite(GREEN, LOW);
  delay(300);

  // 1
  digitalWrite(GREEN, HIGH);
  delay(300);

  // 0
  digitalWrite(GREEN, LOW);
  delay(300);

  // END = BLUE
  digitalWrite(BLUE, HIGH);
  delay(300);
  digitalWrite(BLUE, LOW);

  delay(1000);
}