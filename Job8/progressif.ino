const int led = 6;  // Broche PWM

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Augmente progressivement la luminosité
  for (int intensite = 0; intensite <= 255; intensite++) {
    analogWrite(led, intensite); // PWM entre 0 et 255
    delay(10); // Petit délai pour un effet visible
  }

  // Diminue progressivement la luminosité
  for (int intensite = 255; intensite >= 0; intensite--) {
    analogWrite(led, intensite);
    delay(10);
  }
}
