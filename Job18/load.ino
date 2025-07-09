#include <LiquidCrystal.h>

// LCD classique : rs, en, d4, d5, d6, d7
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int boutonPin = 7;
bool chargementEnCours = false;

// Bloc personnalisé pour la barre
byte bloc[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.createChar(0, bloc);

  pinMode(boutonPin, INPUT_PULLUP);  // Bouton avec résistance pull-up

  lcd_1.setCursor(0, 0);
  lcd_1.print("Appuie bouton");
}

void loop() {
  // Attendre un appui (état bas car pull-up actif)
  if (digitalRead(boutonPin) == LOW && !chargementEnCours) {
    chargementEnCours = true;

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Chargement...");

    // Affiche progressivement la barre
    for (int i = 0; i < 16; i++) {
      lcd_1.setCursor(i, 1);
      lcd_1.write(byte(0));
      delay(3000);  // 3 secondes par bloc

      // Permet l'annulation si tu veux à l'avenir
    }

    // Affichage terminé
    lcd_1.setCursor(0, 0);
    lcd_1.print("Termine !       ");

    // Attend relâchement du bouton
    while (digitalRead(boutonPin) == LOW);
    delay(200);  // anti-rebond

    // Attend prochain appui
    chargementEnCours = false;

    lcd_1.setCursor(0, 1);
    lcd_1.print("Relance: bouton");
  }
}
