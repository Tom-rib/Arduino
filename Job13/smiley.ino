#include <LiquidCrystal.h>

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Définition du caractère smiley (8x5 pixels)
// Chaque octet représente une ligne (5 bits utilisés)
byte smiley[8] = {
  0b00000,
  0b01010,  // Yeux
  0b01010,
  0b00000,
  0b10001,  // Bouche
  0b01110,
  0b00000,
  0b00000
};

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.createChar(0, smiley);    // Enregistre le smiley comme caractère 0
  lcd_1.setCursor(0, 0);
  lcd_1.print("Hello Smiley ");
  lcd_1.setCursor(15, 0);
  lcd_1.write(byte(0));           // Affiche le smiley
}


void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  lcd_1.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd_1.print(seconds);
  delay(1000); // Wait for 1000 millisecond(s)
  seconds += 1;