#include  <Arduino.h>
#include <FastLED.h>
#include <Adafruit_Debounce.h>

#include "hardware/hardwareDefines.h"

#include "models.h"
#include "rand.h"
#include "lights.h"

Player nullPlayer = {};

#ifdef Proto2p

Player players[MAX_PLAYERS] = {
  { PLAYER1, PURPLE,  NULL, false, P1_PX },
  { PLAYER2, BLUE,    NULL, false, P2_PX }
};
Player shuffle[MAX_PLAYERS] = { nullPlayer, nullPlayer };

#else

Player players[MAX_PLAYERS] = {
  { PLAYER1, Color::PURPLE,  P1_PX },
  { PLAYER2, Color::BLUE,    P2_PX },
  { PLAYER3, Color::RED,     P3_PX },
  { PLAYER4, Color::YELLOW,  P4_PX },
  { PLAYER5, Color::GREEN,   P5_PX },
  { PLAYER6, Color::CYAN,    P6_PX }
};
Player shuffle[MAX_PLAYERS] = { nullPlayer, nullPlayer, nullPlayer, nullPlayer, nullPlayer, nullPlayer };

#endif

Player proctor = { PROCTOR, Color::WHITE, PROCTOR_PX };

int pi = 0;

volatile State state = NEUTRAL;
Player player = nullPlayer;
bool firstLoop = true;

void testLoop();
void setState(State s);
Player checkButtons();
void checkProctor();

void setup() {
  Serial.begin(9600);
  long waitUntil = millis() + 1000;
  while (!Serial && waitUntil > millis()) ;
  
  randomSeed(analogRead(ANALOG_SEED_PIN));
  
  lightingSetup();
  
  for (int i = 0; i < MAX_PLAYERS; i++) {
    players[i].debounce = {players[i].pin, LOW};
    players[i].debounce.begin();
  }
  
  proctor.debounce.begin();
}

void loop() {
  if(firstLoop) {
    startupBlink();
    firstLoop = false;
    
    Serial.println("GameBuzzer");
    
    if (digitalRead(PROCTOR) == LOW) setState(TEST);
    else setState(NEUTRAL);
  }

  if (state == TEST) testLoop();
  else {
    if (state == READY) {
      Player p = checkButtons();

      if (p.pin != nullPlayer.pin) {
        player = p;
        setState(BUZZED);
      } else delay(ADA_DEB_DELAY);
    }
    else checkProctor();
  }
}

