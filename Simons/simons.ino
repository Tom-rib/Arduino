// Joue une séquence de succès (clignotement rapide de toutes les LEDs avec un son)
void playSuccessSequence()
{
  for (int i = 0; i < 5; i++) {
    blinkAll(HIGH, 50);
    delay(100);
    blinkAll(LOW, 50);
    delay(100);
  }
  delay(1000);
}

// Joue une séquence d’échec (clignotement plus lent de toutes les LEDs avec un son)
void playFailSequence()
{
  for (int i = 0; i < 3; i++) {
    blinkAll();
    delay(300);
  }
  delay(1000);
}

// Joue une séquence de démarrage (clignotement régulier des LEDs avec un son)
void playStartSequence()
{
  for (int i = 0; i < 3; i++) {
    blinkAll(HIGH, 0);
    delay(300);     
    blinkAll(LOW, 0);    
    delay(300);
  }
  delay(1000);          
}

// Fait clignoter toutes les LEDs avec un état donné (HIGH ou LOW) et une durée de pause
void blinkAll(int state, int delayTime)
{
  for (int i = 0; i < ARRAY_COLLORS_SIZE; i++) {
    playLedTone(ledArray[i]);         
    delay(delayTime);                 
    digitalWrite(ledArray[i], state); 
  }
}

// Fait clignoter toutes les LEDs rapidement (version par défaut sans paramètre)
void blinkAll() {
  blinkAll(HIGH, 0);  
  delay(100);          
  blinkAll(LOW, 0);    
  delay(100);          
}

// Joue une tonalité spécifique sur le buzzer
void playTone(int frequency)
{
  tone(BUZZER, frequency, 100); // Joue le son pendant 100 ms
}

// Joue une tonalité selon la LED correspondante
void playLedTone(int ledPort) {
  switch (ledPort) {
    case GREEN_LED:
      playTone(2000);
      break;
    case YELLOW_LED:
      playTone(2200); 
      break;
    case RED_LED:
      playTone(2400); 
      break;
    case BLUE_LED:
      playTone(2500); 
      break;
  }
}
