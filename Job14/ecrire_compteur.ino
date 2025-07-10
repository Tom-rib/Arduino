#include <LiquidCrystal.h>

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int buttonPin = 7;      // Broche du bouton poussoir
bool compteurEnMarche = true; // État du compteur (démarré / arrêté)
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

int buttonState;
int lastButtonState = HIGH;

unsigned long compteur = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 1000;  // 1 seconde

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Nom du Groupe");  

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Gestion anti-rebond du bouton
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si l'état du bouton a changé
    if (reading != buttonState) {
      buttonState = reading;

      // Bouton pressé (LOW car INPUT_PULLUP)
      if (buttonState == LOW) {
        compteurEnMarche = !compteurEnMarche;  // Inverse l'état du compteur
      
      // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  lcd_1.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd_1.print(seconds);
  delay(1000); 
  seconds += 1;
      
      }
    }
  }

  lastButtonState = reading;

  // Si le compteur est en marche, incrémente toutes les secondes
  if (compteurEnMarche) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      compteur++;
    }
  }

  // Affiche le compteur sur la 2ème ligne (efface avant d'écrire)
  lcd_1.setCursor(0, 1);
  lcd_1.print("Temps:          "); // Effacer l'ancienne valeur
  lcd_1.setCursor(6, 1);
  lcd_1.print(compteur);
}