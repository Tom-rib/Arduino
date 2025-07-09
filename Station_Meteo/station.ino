#include <DHT.h>
#include <LiquidCrystal.h>

// Définition du capteur DHT11
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LCD standard
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Broches RGB (cathode commune)
#define RED_PIN    10
#define GREEN_PIN   9
#define BLUE_PIN    6

void setup() {
  lcd_1.begin(16, 2);
  dht.begin();

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void setColor(int r, int g, int b) {
  // Si LED à cathode commune sur Tinkercad, PWM inversé
  analogWrite(RED_PIN, 255 - r);
  analogWrite(GREEN_PIN, 255 - g);
  analogWrite(BLUE_PIN, 255 - b);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Erreur capteur");
    delay(2000);
    return;
  }

  // Affichage température
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(t);
  lcd_1.print(" C");
  delay(2000);

  // Affichage humidité
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Humidite: ");
  lcd_1.print(h);
  lcd_1.print(" %");
  delay(2000);

  // Couleur de la LED RGB selon la température
  if (t < 20) {
    setColor(0, 0, 255);  // Bleu
  } else if (t < 28) {
    setColor(0, 255, 0);  // Vert
  } else {
    setColor(255, 0, 0);  // Rouge
  }
}
