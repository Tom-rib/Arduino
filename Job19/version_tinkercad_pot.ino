#include <LiquidCrystal.h>

// LCD classique : rs, en, d4, d5, d6, d7
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Broches analogiques des potentiomètres
const int potX = A0;  // remplace VRx
const int potY = A1;  // remplace VRy

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Direction :");
}

void loop() {
  int x = analogRead(potX);  // potentiomètre X
  int y = analogRead(potY);  // potentiomètre Y

  lcd_1.setCursor(0, 1);

  // Interprétation des positions
  if (x < 400) {
    lcd_1.print("Droite         ");
  } else if (x > 600) {
    lcd_1.print("Gauche         ");
  } else if (y < 400) {
    lcd_1.print("Haut           ");
  } else if (y > 600) {
    lcd_1.print("Bas            ");
  } else {
    lcd_1.print("Centre         ");
  }

  delay(200);  // Anti-bruit
}