// C++ code
//
/*
  LiquidCrystal Library - Hello World

   Demonstrates the use of a 16x2 LCD display.
  The LiquidCrystal library works with all LCD
  displays that are compatible with the  Hitachi
  HD44780 driver. There are many of them out
  there, and you  can usually tell them by the
  16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008  by David
  A. Mellis
  library modified 5 Jul 2009  by Limor Fried
  (http://www.ladyada.net)
  example added 9 Jul 2009  by Tom Igoe
  modified 22 Nov 2010  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

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

