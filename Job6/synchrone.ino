// Déclaration des broches des LEDs

const int led1 = 9;
const int led2 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // Allumer les deux LEDs
  digitalWrite(led2, HIGH);
  delay(500);  // Attendre 500 ms

  digitalWrite(led1, LOW);  // Éteindre les deux LEDs
  digitalWrite(led2, LOW);
  delay(500);  // Attendre 500 ms
}