const int potPin = A0;       // Broche du potentiomètre
const int led1Pin = 9;       // LED 1 (intensité directe)
const int led2Pin = 10;      // LED 2 (intensité inverse)

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // Valeur entre 0 et 1023
  int brightness1 = map(potValue, 0, 1023, 0, 255);      // LED 1
  int brightness2 = map(potValue, 0, 1023, 255, 0);      // LED 2 (inverse)

  analogWrite(led1Pin, brightness1);
  analogWrite(led2Pin, brightness2);

  delay(10); // Lissage
}
