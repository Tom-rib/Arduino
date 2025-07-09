#include <LiquidCrystal.h>

// LCD classique
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Pin du signal unique du capteur
const int sigPin = 8;

long duration;
float distance;

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.print("Mesure distance");

  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delay(1000);  // Attendre que tout soit prêt
}

void loop() {
  // Envoi d'une impulsion
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);

  // Lecture de l'écho
  pinMode(sigPin, INPUT);
  duration = pulseIn(sigPin, HIGH);

  // Calcul de la distance
  distance = duration * 0.034 / 2;

  // Affichage LCD
  lcd_1.setCursor(0, 1);
  lcd_1.print("Distance: ");
  lcd_1.print(distance);
  lcd_1.print(" cm   ");

  delay(500);
}
