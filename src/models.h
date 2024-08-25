#include <Adafruit_Debounce.h>

typedef char Pixel;

enum Color {COLOR_OFF, BLUE, RED, YELLOW, PURPLE, CYAN, GREEN, WHITE };

typedef enum {NEUTRAL, READY, BUZZED, TEST} State;

class Player {
  public:
    int pin;
    Color color { Color::COLOR_OFF };
    Adafruit_Debounce debounce;
    bool pressedEarly { false };
    Pixel pixel;

    Player() : debounce(-1, LOW) {
      pin = -1;
    }

    Player(int pin_a, Color color_a, Pixel pixel_a)  : debounce(pin_a, LOW) {
      pin = pin_a;
      color = color_a;
      pixel = pixel_a;
    }

    bool operator ==(const Player& b) {
      return pin == b.pin;
    }
};

String colorToStr(Color color) {
  switch (color) {
    case PURPLE:
      return "Purple";
    case BLUE:
      return "Blue";
    case RED:
      return "Red";
    case YELLOW:
      return "Yellow";
    case CYAN:
      return "Cyan";
    case GREEN:
      return "Green";
    case WHITE:
      return "White";
    case COLOR_OFF:
      return "Off";
    default:
      return "Unknown";
  }
}

String stateToStr(State s) {
  switch (s) {
    case NEUTRAL:
      return "NEUTRAL";
    case READY:
      return "READY";
    case BUZZED:
      return "BUZZED";
    case TEST:
      return "TEST";
    default:
      return "Unknown";
  }
}
