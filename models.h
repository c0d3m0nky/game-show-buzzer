typedef enum {NEUTRAL, READY, BUZZED, TEST} State;

typedef struct {
  int pin;
  Color color;
  Adafruit_Debounce debounce;
  bool pressedEarly;
  Pixel pixel;
} Player;

Player nullPlayer = { -1, WHITE, -1};

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
