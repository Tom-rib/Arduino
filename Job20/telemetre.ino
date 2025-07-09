#include <LiquidCrystal.h>

// Déclaration de l'écran LCD : rs, en, d4, d5, d6, d7
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Pins du capteur HC-SR04
const int trigPin = 8;
const int echoPin = 9;

long duration;
float distance;

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.print("Mesure distance");
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(1000);
}

void loop() {
  // Envoi d'une impulsion ultrasonique
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lecture de la durée du retour de l’écho
  duration = pulseIn(echoPin, HIGH);

  // Calcul de la distance en cm
  distance = duration * 0.034 / 2;

  // Affichage sur l’écran LCD
  lcd_1.setCursor(0, 1);
  lcd_1.print("Distance: ");
  lcd_1.print(distance);
  lcd_1.print(" cm  ");

  delay(500);
}
