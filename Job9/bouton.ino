const int ledPin = 6;
const int buttonPin = 2;

unsigned long lastPressTime = 0;
unsigned long pressDuration = 0;
unsigned long lastClickTime = 0;

int clickCount = 0;
bool ledState = false;
bool blinking = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Bouton connecté à GND
  Serial.begin(9600);
}

void loop() {
  static bool previousButtonState = HIGH;
  bool currentButtonState = digitalRead(buttonPin);

  unsigned long now = millis();

  // Détection d'appui
  if (previousButtonState == HIGH && currentButtonState == LOW) {
    lastPressTime = now;
  }

  // Détection relâchement
  if (previousButtonState == LOW && currentButtonState == HIGH) {
    pressDuration = now - lastPressTime;

    // Appui long (≥ 2 sec)
    if (pressDuration >= 2000) {
      ledState = false;
      blinking = false;
      digitalWrite(ledPin, LOW);
      clickCount = 0;
      Serial.println("Appui long - LED éteinte");
    } else {
      clickCount++;
      lastClickTime = now;
    }
  }

  previousButtonState = currentButtonState;

  // Gestion des clics (après délai d'inactivité)
  if (clickCount > 0 && (now - lastClickTime > 500)) {
    if (clickCount == 1) {
      Serial.println("1 clic - LED allumée temporairement");
      ledState = true;
      blinking = false;
    } else if (clickCount == 2) {
      Serial.println("2 clics - LED reste allumée");
      ledState = true;
      blinking = false;
    } else if (clickCount == 3) {
      Serial.println("3 clics - LED clignote");
      blinking = true;
    }
    clickCount = 0;
  }

  // Gérer clignotement si actif
  if (blinking) {
    static unsigned long lastBlink = 0;
    static bool blinkState = false;

    if (now - lastBlink >= 500) {
      blinkState = !blinkState;
      digitalWrite(ledPin, blinkState ? HIGH : LOW);
      lastBlink = now;
    }
  } else {
    digitalWrite(ledPin, ledState ? HIGH : LOW);
  }
}
