void playSuccessSequence()
{
  for(int i=0; i < 5; i++){
    blinkAll(HIGH, 50);
    delay(100);
    blinkAll(LOW, 50);
    delay(100);
  }
  delay(1000);
}

void playFailSequence()
{
   for(int i=0; i < 3; i++){
    blinkAll();
    delay(300);
  }
  delay(1000);
}

void playStartSequence()
{
  for(int i=0; i < 3; i++){
    blinkAll(HIGH, 0);
    delay(300);
    blinkAll(LOW, 0);
    delay(300);
  }
  delay(1000);
}

void blinkAll(int state, int delayTime)
{
  for(int i=0; i < ARRAY_COLLORS_SIZE; i++){
    playLedTone(ledArray[i]);
    delay(delayTime);
    digitalWrite(ledArray[i], state);
  }
}

void blinkAll(){
  blinkAll(HIGH, 0);
  delay(100);
  blinkAll(LOW, 0);
  delay(100);
}

void playTone(int frequency)
{
  tone(BUZZER, frequency, 100);
}

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