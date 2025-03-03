
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
#define ANALOG_SEED_PIN 7

#endif

// Lights

#ifdef Proto2p

#undef  Stubs
#define MAX_PLAYERS     2

#include "Proto2p.h"

#endif

#ifdef NeoP24KO

#undef  Stubs
#include "NeoP24KO.h"

#endif
