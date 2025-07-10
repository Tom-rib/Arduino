#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int pinTMP36 = A0;
const int pinHumidite = A1;

// LED RGB
const int pinRouge = 10;
const int pinVert = 9;
const int pinBleu = 6;

void setup() {
  lcd_1.begin(16, 2);
  pinMode(pinRouge, OUTPUT);
  pinMode(pinVert, OUTPUT);
  pinMode(pinBleu, OUTPUT);
}

void setColor(int r, int g, int b) {
  analogWrite(pinRouge, 255 - r);
  analogWrite(pinVert, 255 - g);
  analogWrite(pinBleu, 255 - b);
}

void loop() {
  int valTMP = analogRead(pinTMP36);
  float tension = valTMP * (5.0 / 1023.0);
  float temperature = (tension - 0.5) * 100.0;

  int humiditeBrute = analogRead(pinHumidite);
  int humiditePourcent = map(humiditeBrute, 1023, 0, 100, 0);

  // LED RGB selon température
  if (temperature < 18) {
    setColor(0, 0, 255);     // Bleu
  } else if (temperature < 25) {
    setColor(0, 255, 0);     // Vert
  } else {
    setColor(255, 0, 0);     // Rouge
  }

  // Affichage propre
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(temperature, 1);
  lcd_1.print(" C   ");  // efface les anciens caractères

  lcd_1.setCursor(0, 1);
  lcd_1.print("Hum:  ");
  lcd_1.print(humiditePourcent);
  lcd_1.print(" %   "); // idem ici

  delay(1000);
}

