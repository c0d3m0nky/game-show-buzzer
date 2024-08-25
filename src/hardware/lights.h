
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
  delay(1000);
}

#endif

#if !defined(ControllerBlink) && defined(Stubs)

void startupBlink() {
  Serial.println("λ - startupBlink()");
}

#endif

#ifdef Stubs

void doRainbowVomit() {
  Serial.println("λ - doRainbowVomit()");
}

void allOff(bool draw=true) {
  Serial.println("λ - allOff()");
}

void draw() {
  
}

void setColor(Color color) {
  Serial.println("λ - setColor(" + colorToStr(color) + ")");
}

void setPixel(Pixel pixel, Color color) {
//  Serial.println("λ - setPixel(" + String(pixel) + ", " + colorToStr(color) + ")");
}

#endif
