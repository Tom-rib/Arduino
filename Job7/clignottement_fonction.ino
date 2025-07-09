// Déclaration des broches des LEDs
const int leds[] = {6, 7, 8, 9, 10, 11, 12, 13};
const int nbLeds = sizeof(leds) / sizeof(leds[0]);

void setup() {
  for (int i = 0; i < nbLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void clignoterLed(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

void loop() {
  for (int i = 0; i < nbLeds; i++) {
    clignoterLed(leds[i]);
  }
}
