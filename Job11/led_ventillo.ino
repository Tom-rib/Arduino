const int buttonPin = 2;
const int ledPin = 6;
const int fanPin = 9;

bool ledOn = false;
bool fanOn = false;
unsigned long ledStartTime = 0;
bool waitingForFan = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Bouton actif bas
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(fanPin, LOW);
}

void loop() {
  static bool lastButtonState = HIGH;
  bool currentButtonState = digitalRead(buttonPin);

  // Détection d’appui (front descendant)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (!ledOn && !fanOn) {
      // Allumer LED et démarrer le compte à rebours
      ledOn = true;
      ledStartTime = millis();
      waitingForFan = true;
      digitalWrite(ledPin, HIGH);
    } else if (fanOn) {
      // Si le ventilateur tourne → l’éteindre
      fanOn = false;
      digitalWrite(fanPin, LOW);
    }
  }

  lastButtonState = currentButtonState;

  // Gérer extinction LED et allumage ventilateur après 15s
  if (waitingForFan && (millis() - ledStartTime >= 15000)) {
    ledOn = false;
    fanOn = true;
    waitingForFan = false;
    digitalWrite(ledPin, LOW);
    digitalWrite(fanPin, HIGH);
  }
}
