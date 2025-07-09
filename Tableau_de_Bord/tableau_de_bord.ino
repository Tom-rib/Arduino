#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int pinTMP36 = A0;
const int pinHumidite = A1;
const int pinPhoto = 7;
const int pinUltrason = 8;

const int ledBleue = A2;
const int ledRouge = A3;
const int ledVerte = A4;
const int ledJaune = A5;
const int ventilateur = 6;
const int buzzer = 13;

const int boutonStart = 10;
const int boutonSuivant = 9;

int ecran = 0;
int ecranAffiche = -1;
bool systemeActive = false;
bool boutonStartPressed = false;
unsigned long boutonStartPressTime = 0;
unsigned long dernierAppuiSuivant = 0;

void setup() {
  lcd_1.begin(16, 2);
  pinMode(pinUltrason, OUTPUT);
  pinMode(pinPhoto, INPUT);
  pinMode(ledBleue, OUTPUT);
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVerte, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ventilateur, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(boutonStart, INPUT_PULLUP);
  pinMode(boutonSuivant, INPUT_PULLUP);
  
  // Affichage initial
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Pret > Start Btn");
}

void loop() {
  // Gestion du bouton Start (appui long pour arrêter, court pour démarrer)
  if (digitalRead(boutonStart) == LOW) {
    if (!boutonStartPressed) {
      boutonStartPressed = true;
      boutonStartPressTime = millis();
    } else {
      if (systemeActive && (millis() - boutonStartPressTime > 1500)) {
        // Arrêt du système
        systemeActive = false;
        lcd_1.clear();
        lcd_1.setCursor(0,0);
        lcd_1.print("Systeme arrete");
        delay(1000);
        lcd_1.clear();
        lcd_1.setCursor(0,0);
        lcd_1.print("Pret > Start Btn");
        ecranAffiche = -1; 
        boutonStartPressed = false;
        return;
      }
    }
  } else {
    if (boutonStartPressed) {
      if (!systemeActive && (millis() - boutonStartPressTime < 1500)) {
        // Démarrage du système
        systemeActive = true;
        lcd_1.clear();
        lcd_1.setCursor(0,0);
        lcd_1.print("Systeme actif");
        ecranAffiche = -1; // Force l'affichage du premier écran
      }
      boutonStartPressed = false;
    }
  }

  if (!systemeActive) return;

  // Lecture capteurs
  float temperature = lireTemperature();
  int humidite = lireHumidite();
  int lumiere = digitalRead(pinPhoto);
  int distance = lireDistance();

  // Gestion actionneurs (toujours actifs)
  gererTemperature(temperature);
  gererHumidite(humidite);
  gererDistance(distance);

  // Changement écran UNIQUEMENT sur appui bouton suivant
  if (digitalRead(boutonSuivant) == LOW && millis() - dernierAppuiSuivant > 300) {
    ecran = (ecran + 1) % 4;
    // Met à jour l'affichage immédiatement lors du changement d'écran
    afficherEcran(ecran, temperature, humidite, lumiere, distance);
    ecranAffiche = ecran;
    dernierAppuiSuivant = millis();
  }

  // Affichage initial uniquement (quand le système vient de démarrer)
  if (ecranAffiche == -1) {
    afficherEcran(ecran, temperature, humidite, lumiere, distance);
    ecranAffiche = ecran;
  }

  delay(200);
}

void afficherEcran(int e, float temperature, int humidite, int lumiere, int distance) {
  lcd_1.clear(); // Efface tout l'écran
  lcd_1.setCursor(0,0);
  lcd_1.print("Systeme actif"); // ligne 1 fixe

  lcd_1.setCursor(0,1);
  switch (e) {
    case 0:
      lcd_1.print("Temp: ");
      lcd_1.print(temperature, 1);
      lcd_1.print(" C");
      break;
    case 1:
      lcd_1.print("Humidite: ");
      lcd_1.print(humidite);
      lcd_1.print("%");
      break;
    case 2:
      lcd_1.print("Lumiere: ");
      lcd_1.print(lumiere ? "Clair" : "Sombre");
      break;
    case 3:
      if (distance < 0) {
        lcd_1.print("Distance: No");
        lcd_1.setCursor(0,1);
        lcd_1.print(" mesure");
      } else {
        lcd_1.print("Distance: ");
        lcd_1.print(distance);
        lcd_1.print(" cm");
      }
      break;
  }
}

float lireTemperature() {
  int val = analogRead(pinTMP36);
  float tension = val * (5.0 / 1023.0);
  float temperature = (tension - 0.5) * 100;
  return temperature;
}

int lireHumidite() {
  int val = analogRead(pinHumidite);
  return map(val, 1023, 0, 0, 100);
}

int lireDistance() {
  pinMode(pinUltrason, OUTPUT);
  digitalWrite(pinUltrason, LOW);
  delayMicroseconds(2);
  digitalWrite(pinUltrason, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinUltrason, LOW);

  pinMode(pinUltrason, INPUT);
  long duree = pulseIn(pinUltrason, HIGH, 25000);
  pinMode(pinUltrason, OUTPUT);

  if (duree == 0) return -1;
  return duree * 0.034 / 2;
}

void gererTemperature(float t) {
  digitalWrite(ledBleue, LOW);
  digitalWrite(ledRouge, LOW);
  digitalWrite(ventilateur, LOW);

  if (t >= 10 && t <= 18) {
    digitalWrite(ledBleue, HIGH);
  } else if (t >= 19 && t <= 21) {
    digitalWrite(ledRouge, HIGH);
  } else if (t > 22) {
    digitalWrite(ventilateur, HIGH);
  }
}

void gererHumidite(int h) {
  digitalWrite(ledVerte, LOW);
  digitalWrite(ledJaune, LOW);

  if (h >= 40 && h <= 70) {
    digitalWrite(ledVerte, HIGH);
  } else {
    digitalWrite(ledJaune, HIGH);
  }
}

void gererDistance(int d) {
  if (d > 0 && d < 20) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
}