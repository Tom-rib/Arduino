#include <LiquidCrystal.h>

// Configuration LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pins des capteurs
const int pinTMP36 = A0;
const int pinHumidite = A1;
const int pinPhoto = 7;
const int pinUltrasonSig = 8;

// Pins des actionneurs
const int ledBleue = A2;
const int ledRouge = A3;
const int ledVerte = A4;
const int ledJaune = A5;
const int ventilateur = 6;
const int buzzer = 13;

// Pins des boutons
const int boutonStart = 10;
const int boutonSuivant = 9;

// Variables système
bool systemeActive = false;
bool boutonStartPressed = false;
unsigned long boutonStartPressTime = 0;
int ecranActuel = 0;
int dernierEcranAffiche = -1;
unsigned long dernierAppuiSuivant = 0;
bool dernierEtatBoutonSuivant = HIGH;

// Variables pour rafraîchissement automatique
unsigned long dernierAffichage = 0;
const unsigned long intervalleAffichage = 1000;

// Variables des capteurs
const int nbLectures = 5;
float temperature = 0.0;
int humidite = 0;
int lumiere = 0;
int distance = -1;
float tempBuffer[nbLectures] = {0};
int humBuffer[nbLectures] = {0};
int distBuffer[nbLectures] = {0};
int indexLecture = 0;

void setup() {
  lcd.begin(16, 2);
  
  pinMode(pinUltrasonSig, OUTPUT);
  digitalWrite(pinUltrasonSig, LOW);
  pinMode(pinPhoto, INPUT);
  
  pinMode(ledBleue, OUTPUT);
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVerte, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ventilateur, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(boutonStart, INPUT_PULLUP);
  pinMode(boutonSuivant, INPUT_PULLUP);

  for (int i = 0; i < nbLectures; i++) {
    tempBuffer[i] = lireTemperatureBrute();
    humBuffer[i] = lireHumiditeBrute();
    distBuffer[i] = lireDistanceBrute();
    delay(10);
  }

  afficherEcranInitial();
}

void loop() {
  gererBoutons();
  lireCapteurs();
  afficherDonnees();
  controlerActionneurs();
  delay(100);
}

void afficherEcranInitial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pret > Start Btn");
}

void gererBoutons() {
  // Gestion bouton Start
  bool startAppuye = digitalRead(boutonStart) == LOW;

  if (startAppuye && !boutonStartPressed) {
    boutonStartPressed = true;
    boutonStartPressTime = millis();
  }

  if (!startAppuye && boutonStartPressed) {
    unsigned long dureeAppui = millis() - boutonStartPressTime;

    if (!systemeActive && dureeAppui < 5000) {
      activerSysteme();
    } else if (systemeActive && dureeAppui >= 5000) {
      desactiverSysteme();
    }

    boutonStartPressed = false;
  }

  // Gestion bouton Suivant
  bool etatActuelBoutonSuivant = digitalRead(boutonSuivant);
  
  if (etatActuelBoutonSuivant == LOW && dernierEtatBoutonSuivant == HIGH) {
    if (systemeActive && millis() - dernierAppuiSuivant > 300) {
      ecranActuel = (ecranActuel + 1) % 4;
      dernierAppuiSuivant = millis();
    }
  }
  
  dernierEtatBoutonSuivant = etatActuelBoutonSuivant;
}

void activerSysteme() {
  systemeActive = true;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Systeme actif");
  afficherDonneesCapteur();
}

void desactiverSysteme() {
  systemeActive = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Systeme inactif");
  
  digitalWrite(ledBleue, LOW);
  digitalWrite(ledRouge, LOW);
  digitalWrite(ledVerte, LOW);
  digitalWrite(ledJaune, LOW);
  digitalWrite(ventilateur, LOW);
  digitalWrite(buzzer, LOW);
  
  dernierEcranAffiche = -1;
}

void lireCapteurs() {
  if (!systemeActive) return;

  tempBuffer[indexLecture] = lireTemperatureBrute();
  humBuffer[indexLecture] = lireHumiditeBrute();
  distBuffer[indexLecture] = lireDistanceBrute();
  lumiere = digitalRead(pinPhoto);
  
  indexLecture = (indexLecture + 1) % nbLectures;

  temperature = calculerMoyenne(tempBuffer, nbLectures);
  humidite = calculerMoyenne(humBuffer, nbLectures);
  distance = calculerMoyenne(distBuffer, nbLectures);
}

void afficherDonnees() {
  if (!systemeActive) return;

  if (millis() - dernierAffichage > intervalleAffichage || dernierEcranAffiche != ecranActuel) {
    afficherDonneesCapteur();
    dernierAffichage = millis();
    dernierEcranAffiche = ecranActuel;
  }
}

void afficherDonneesCapteur() {
  lcd.setCursor(0, 1);
  lcd.print("                "); // efface ligne
  
  switch (ecranActuel) {
    case 0:
      lcd.setCursor(0, 1);
      lcd.print("Temp: ");
      lcd.print(temperature, 1);
      lcd.print(" C");
      break;
      
    case 1:
      lcd.setCursor(0, 1);
      lcd.print("Humidite: ");
      lcd.print(humidite);
      lcd.print("%");
      break;
      
    case 2:
      lcd.setCursor(0, 1);
      lcd.print("Lumiere: ");
      lcd.print(lumiere ? "Clair" : "Sombre");
      break;
      
    case 3:
      lcd.setCursor(0, 1);
      if (distance < 0) {
        lcd.print("Distance: NoMesure");
      } else {
        lcd.print("Distance: ");
        lcd.print(distance);
        lcd.print(" cm");
      }
      break;
  }
}

void controlerActionneurs() {
  if (!systemeActive) return;

  digitalWrite(ledBleue, LOW);
  digitalWrite(ledRouge, LOW);
  digitalWrite(ventilateur, LOW);
  
  if (temperature >= 10 && temperature <= 18) {
    digitalWrite(ledBleue, HIGH);
  } else if (temperature >= 19 && temperature <= 21) {
    digitalWrite(ledRouge, HIGH);
  } else if (temperature > 22) {
    digitalWrite(ventilateur, HIGH);
  }

  digitalWrite(ledVerte, LOW);
  digitalWrite(ledJaune, LOW);
  
  if (humidite >= 40 && humidite <= 70) {
    digitalWrite(ledVerte, HIGH);
  } else {
    digitalWrite(ledJaune, HIGH);
  }

  if (distance > 0 && distance < 20) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
}

float calculerMoyenne(float* buffer, int taille) {
  float somme = 0;
  for (int i = 0; i < taille; i++) {
    somme += buffer[i];
  }
  return somme / taille;
}

int calculerMoyenne(int* buffer, int taille) {
  long somme = 0;
  for (int i = 0; i < taille; i++) {
    somme += buffer[i];
  }
  return somme / taille;
}

float lireTemperatureBrute() {
  int val = analogRead(pinTMP36);
  float tension = val * (5.0 / 1023.0);
  return (tension - 0.5) * 100;
}

int lireHumiditeBrute() {
  int val = analogRead(pinHumidite);
  return map(val, 0, 1023, 0, 100);
}

int lireDistanceBrute() {
  pinMode(pinUltrasonSig, OUTPUT);
  digitalWrite(pinUltrasonSig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinUltrasonSig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinUltrasonSig, LOW);

  pinMode(pinUltrasonSig, INPUT);
  long duree = pulseIn(pinUltrasonSig, HIGH, 30000);
  
  return (duree == 0) ? -1 : duree * 0.034 / 2;
}
