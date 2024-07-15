
#if defined(ControllerBlink) && defined(SeedXiao)

void startupBlink() {
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY*2);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY*4);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY*2);
  digitalWrite(LED, LED_ON);
  delay(LED_DELAY);
  digitalWrite(LED, LED_OFF);
  delay(LED_DELAY*2);
}

#endif

#if !defined(ControllerBlink) && defined(Stubs)

void startupBlink() {
  Serial.println("λ - startupBlink()");
}

#endif

#ifdef Stubs

void startRainbowVomit() {
  Serial.println("λ - startRainbowVomit()");
}

void stopRainbowVomit() {
  Serial.println("λ - stopRainbowVomit()");
}

void allOff() {
  Serial.println("λ - allOff()");
}

void setColor(Color color) {
  Serial.println("λ - setColor(" + colorToStr(color) + ")");
}

void setPixel(Pixel pixel, Color color) {
//  Serial.println("λ - setPixel(" + String(pixel) + ", " + colorToStr(color) + ")");
}

#endif

#ifdef Proto2p

void allOff() {
  digitalWrite(GREEN_LV, LED_OFF);
  digitalWrite(PURPLE_LV, LED_OFF);
  digitalWrite(BLUE_LV, LED_OFF);
}

void allOn() {
  digitalWrite(GREEN_LV, LED_ON);
  digitalWrite(PURPLE_LV, LED_ON);
  digitalWrite(BLUE_LV, LED_ON);
}

void setColor(Color color) {
//  Serial.println("λ - setColor(" + colorToStr(color) + ")");
  allOff();
  
  switch (color) {
    case GREEN:
      digitalWrite(GREEN_LV, LED_ON);
      break;
    case PURPLE:
      digitalWrite(PURPLE_LV, LED_ON);
      break;
    case BLUE:
      digitalWrite(BLUE_LV, LED_ON);
      break;
    default:
      break;
  }
}

void startRainbowVomit() {
  allOff();
  setColor(GREEN);
  delay(LED_DELAY);
  allOff();
  allOff();
  setColor(PURPLE);
  delay(LED_DELAY);
  allOff();
  allOff();
  setColor(BLUE);
  delay(LED_DELAY);
  allOff();
}

void stopRainbowVomit() {
//  Serial.println("λ - stopRainbowVomit()");
}

void setPixel(Pixel pixel, Color color) {
//  Serial.println("λ - setPixel(" + String(pixel) + ", " + colorToStr(color) + ")");
  if (color == COLOR_OFF) digitalWrite(pixel, LED_OFF);
  else digitalWrite(pixel, LED_ON);
}

void startupBlink() {
  allOff();
  delay(LED_DELAY);
  allOn();
  delay(LED_DELAY*2);
  allOff();
  delay(LED_DELAY);
  allOn();
  delay(LED_DELAY);
  allOff();
  delay(LED_DELAY);
  allOn();
  delay(LED_DELAY);
  allOff();
  delay(LED_DELAY);
  allOn();
  delay(LED_DELAY);
  allOff();
  delay(LED_DELAY);
  allOn();
  delay(LED_DELAY);
  allOff();
  delay(LED_DELAY*4);
  allOn();
  delay(LED_DELAY);
  allOff();
  delay(LED_DELAY*2);
  allOn();
  delay(LED_DELAY);
  allOff();
  delay(LED_DELAY*2);
}

#endif
