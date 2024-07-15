
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
