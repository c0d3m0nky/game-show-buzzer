#include  <Arduino.h>
#include "models.h"

#define LED_ON          HIGH
#define LED_OFF         LOW

#define PROCTOR_PX      10
#define P1_PX           9
#define P2_PX           8
#define PURPLE_LV       9
#define BLUE_LV         8
#define GREEN_LV        10
#define WHITE_LV        10
#define MIN_LIGHT_DELAY 10

typedef int  Pixel;

void lightingSetup() {
  pinMode(PURPLE_LV, OUTPUT);
  pinMode(BLUE_LV, OUTPUT);
  pinMode(GREEN_LV, OUTPUT);
}


void allOff(bool draw=true) {
  digitalWrite(GREEN_LV, LED_OFF);
  digitalWrite(PURPLE_LV, LED_OFF);
  digitalWrite(BLUE_LV, LED_OFF);
}

void allOn() {
  digitalWrite(GREEN_LV, LED_ON);
  digitalWrite(PURPLE_LV, LED_ON);
  digitalWrite(BLUE_LV, LED_ON);
}

void draw() {
  
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

void doRainbowVomit() {
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
  delay(1000);
}
