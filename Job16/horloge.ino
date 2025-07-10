#include <LiquidCrystal.h>

// LiquidCrystal(rs, en, d4, d5, d6, d7)
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Variables d'heure
int heures = 0;
int minutes = 0;
int secondes = 0;

unsigned long dernierMillis = 0;

void setup() {
  lcd_1.begin(16, 2);         // Initialisation LCD
  lcd_1.setCursor(0, 0);
  lcd_1.print("Horloge:");
}

void loop() {
  unsigned long tempsActuel = millis();

  // Incrément toutes les secondes
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

    // Affiche HH:MM:SS ligne 2
    lcd_1.setCursor(0, 1);
    if (heures < 10) lcd_1.print("0");
    lcd_1.print(heures);
    lcd_1.print(":");

    if (minutes < 10) lcd_1.print("0");
    lcd_1.print(minutes);
    lcd_1.print(":");

    if (secondes < 10) lcd_1.print("0");
    lcd_1.print(secondes);


  }
}

