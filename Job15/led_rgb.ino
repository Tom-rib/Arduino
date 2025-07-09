const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int potPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);  // Plage : 0 à 1023

  // Convertir la valeur du potentiomètre en une plage de 0 à 765
  int colorValue = map(potValue, 0, 1023, 0, 765);

  int red, green, blue;

  // Dégradé fluide : rouge -> vert -> bleu
  if (colorValue <= 255) {
    red = 255 - colorValue;
    green = colorValue;
    blue = 0;
  } else if (colorValue <= 510) {
    red = 0;
    green = 510 - colorValue;
    blue = colorValue - 255;
  } else {
    red = colorValue - 510;
    green = 0;
    blue = 765 - colorValue;
  }

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  delay(10);
}
