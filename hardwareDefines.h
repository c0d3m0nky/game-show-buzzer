
#define LED_ON          LOW
#define LED_OFF         HIGH

// Controllers
#ifdef SeedXiao

#define Stubs
#define LED             13
#define PROCTOR         0
#define PLAYER1         1
#define PLAYER2         2
#define PLAYER3         3
#define PLAYER4         4
#define PLAYER5         5
#define PLAYER6         6
#define PLAYER7         7
#define ANALOG_SEED_PIN 7

#endif

// Lights

//typedef char  Pixel;

#ifdef Proto2p

#undef  Stubs
typedef int  Pixel;
#define MAX_PLAYERS     2

#define LED_ON          HIGH
#define LED_OFF         LOW

#define PROCTOR_PX      10
#define P1_PX           9
#define P2_PX           8
#define P3_PX           -1
#define P4_PX           -1
#define P5_PX           -1
#define P6_PX           -1
#define P7_PX           -1
#define PURPLE_LV       9
#define BLUE_LV         8
#define RED_LV          -1
#define YELLOW_LV       -1
#define MAGENTA_LV      -1
#define CYAN_LV         -1
#define ORANGE_LV       -1
#define GREEN_LV        10
#define WHITE_LV        10
#define RBV_CYCLE       10
#define MIN_LIGHT_DELAY 10

void lightingSetup() {
  pinMode(PURPLE_LV, OUTPUT);
  pinMode(BLUE_LV, OUTPUT);
  pinMode(GREEN_LV, OUTPUT);
}

#endif
