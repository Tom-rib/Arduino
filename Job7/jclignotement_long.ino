// Déclaration des broches des LEDs


const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;
const int led5 = 10;
const int led6 = 11;
const int led7 = 12;
const int led8 = 13;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led1, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms


  digitalWrite(led2, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led2, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms

  digitalWrite(led3, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led3, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms


  digitalWrite(led4, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led4, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms

    digitalWrite(led5, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led5, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms


  digitalWrite(led6, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led6, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms

    digitalWrite(led7, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led7, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms


  digitalWrite(led8, HIGH);  // Allumer les deux LEDs
  delay(500);  // Attendre 500 ms
  digitalWrite(led8, LOW);  // Éteindre les deux LEDs
  delay(500);  // Attendre 500 ms


}