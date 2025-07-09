#include <LiquidCrystal.h>

// LCD standard (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int boutonPin = 7;

bool enMarche = false;
bool etatBoutonPrecedent = LOW;
unsigned long tempsAppui = 0;
unsigned long tempsDepart = 0;
unsigned long tempsActuel = 0;

void setup() {
  pinMode(boutonPin, INPUT);
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Chronometre:");
  lcd_1.setCursor(0, 1);
  lcd_1.print("00:00:00");
}

void loop() {
  bool boutonEtat = digitalRead(boutonPin);
  unsigned long maintenant = millis();

  // Détection de l’appui
  if (boutonEtat == HIGH && etatBoutonPrecedent == LOW) {
    tempsAppui = maintenant;
  }

  // Relâchement du bouton
  if (boutonEtat == LOW && etatBoutonPrecedent == HIGH) {
    unsigned long dureeAppui = maintenant - tempsAppui;

    if (dureeAppui >= 2000) {
      // Appui long : RESET
      enMarche = false;
      tempsDepart = 0;
      tempsActuel = 0;
      lcd_1.setCursor(0, 1);
      lcd_1.print("00:00:00        ");
    } else {
      // Appui court : START / PAUSE
      enMarche = !enMarche;
      if (enMarche) {
        tempsDepart = maintenant - tempsActuel; // reprendre
      }
    }
  }

  etatBoutonPrecedent = boutonEtat;

  if (enMarche) {
    tempsActuel = maintenant - tempsDepart;

    int secondes = (tempsActuel / 1000) % 60;
    int minutes  = (tempsActuel / 60000) % 60;
    int heures   = (tempsActuel / 3600000);

    lcd_1.setCursor(0, 1);
    if (heures < 10) lcd_1.print("0");
    lcd_1.print(heures);
    lcd_1.print(":");

    if (minutes < 10) lcd_1.print("0");
    lcd_1.print(minutes);
    lcd_1.print(":");

    if (secondes < 10) lcd_1.print("0");
    lcd_1.print(secondes);
    lcd_1.print("        "); // Nettoyage
  }
}
