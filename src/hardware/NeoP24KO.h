#include <FastLED.h>
#include "models.h"

#define FLED_DATA       10
#define NUM_LEDS        24
#define PROCTOR_PX      0
#define P1_PX           1
#define P2_PX           2
#define P3_PX           3
#define P4_PX           4
#define P5_PX           5
#define P6_PX           6
#define PURPLE_LV       CRGB::Magenta
#define BLUE_LV         CRGB::Blue
#define RED_LV          CRGB::Red
#define YELLOW_LV       CRGB::Gold
#define CYAN_LV         CRGB::Cyan
#define GREEN_LV        CRGB::Green
#define WHITE_LV        CRGB::White
#define COLOR_OFF_LV    CRGB::Black
#define PIXEL_SIZE      3


typedef char PixelRange[PIXEL_SIZE];

CRGB leds[NUM_LEDS];
PixelRange pixels[MAX_PLAYERS + 1] = {
  {1,2,3}, // Proctor
  {5,6,7}, // Player 1
  {8,9,10}, // Player 2
  {11,12,13}, // Player 3
  {14,15,16}, // Player 4
  {17,18,19}, // Player 5
  {20,21,22}, // Player 6
};

void lightingSetup() {
  FastLED.addLeds<NEOPIXEL, FLED_DATA>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
}

CRGB translateColor(Color color) {
  switch (color) {
    case PURPLE:
      return PURPLE_LV;
    case BLUE:
      return BLUE_LV;
    case RED:
      return RED_LV;
    case YELLOW:
      return YELLOW_LV;
    case CYAN:
      return CYAN_LV;
    case GREEN:
      return GREEN_LV;
    case WHITE:
      return WHITE_LV;
    case COLOR_OFF:
      return COLOR_OFF_LV;
    default:
      return COLOR_OFF_LV;
  }
}


void rainbow_march(uint8_t thisSpeed) { 
  uint8_t thisHue = beat8(thisSpeed,255);  
  fill_rainbow_circular(leds, NUM_LEDS, thisHue);
 
}

void rainbow_wave(uint8_t thisSpeed) { 
  uint8_t thisHue = beatsin8(thisSpeed,0,255);
  fill_rainbow_circular(leds, NUM_LEDS, thisHue);
}

void startupBlink() {
  long until = millis() + 3000;

  while (millis() < until) {
    rainbow_march(200);
    FastLED.show();
  }
}

void doRainbowVomit() {
  long until = millis() + 1000;

  while (millis() < until) {
    rainbow_wave(200);
    FastLED.show();
  }  
}

void setColor(Color color) {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i] = translateColor(color); }
  FastLED.show();
}

void allOff(bool draw=true) {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i] = COLOR_OFF_LV; }
  if (draw) FastLED.show();
}

void draw() {
  FastLED.show();
}

void setPixel(Pixel pixel, Color color) {
  CRGB c = translateColor(color);
  leds[pixels[pixel][0]] = c;
  leds[pixels[pixel][1]] = c;
  leds[pixels[pixel][2]] = c;
  FastLED.show();
}
