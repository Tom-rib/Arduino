#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adresse I2C 0x27 (changer en 0x3F si nécessaire)
LiquidCrystal_I2C lcd(0x20, 16, 2);

// Variables d'heure
int heures = 0;
int minutes = 0;
int secondes = 0;

unsigned long dernierMillis = 0;

void setup() {
  lcd.begin();          // Initialisation I2C
  lcd.backlight();      // Active le rétroéclairage
  lcd.setCursor(0, 0);
  lcd.print("Horloge:");
}

void loop() {
  unsigned long tempsActuel = millis();

  if (tempsActuel - dernierMillis >= 1000) {
    dernierMillis = tempsActuel;
    secondes++;

    if (secondes >= 60) {
      secondes = 0;
      minutes++;
    }

    if (minutes >= 60) {
      minutes = 0;
      heures++;
    }

    if (heures >= 24) {
      heures = 0;
    }

    // Affiche HH:MM:SS
    lcd.setCursor(0, 1);

    if (heures < 10) lcd.print("0");
    lcd.print(heures);
    lcd.print(":");

    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print(":");

    if (secondes < 10) lcd.print("0");
    lcd.print(secondes);
  }
}
