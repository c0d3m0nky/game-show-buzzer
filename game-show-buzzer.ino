//#define DEBUG
#define LED_DELAY     125
#define MAX_PLAYERS   7
#define ADA_DEB_DELAY 7

// hardware
#define   SeedXiao
#define   Proto2p
#include  "hardwareDefines.h"

#include "Adafruit_Debounce.h"
#include "models.h"
#include "rand.h"
#include "lights.h"

#ifdef Proto2p

#define MAX_PLAYERS   2

Player players[MAX_PLAYERS] = {
  { PLAYER1, PURPLE,  NULL, false, P1_PX },
  { PLAYER2, BLUE,    NULL, false, P2_PX }
};
Player shuffle[MAX_PLAYERS] = { nullPlayer, nullPlayer };

#else

Player players[MAX_PLAYERS] = {
  { PLAYER1, PURPLE,  NULL, false, P1_PX },
  { PLAYER2, BLUE,    NULL, false, P2_PX },
  { PLAYER3, RED,     NULL, false, P3_PX },
  { PLAYER4, YELLOW,  NULL, false, P4_PX },
  { PLAYER5, MAGENTA, NULL, false, P5_PX },
  { PLAYER6, CYAN,    NULL, false, P6_PX },
  { PLAYER7, ORANGE,  NULL, false, P7_PX }
};
Player shuffle[MAX_PLAYERS] = { nullPlayer, nullPlayer, nullPlayer, nullPlayer, nullPlayer, nullPlayer, nullPlayer };

#endif

Player proctor = { PROCTOR, WHITE, {PROCTOR, LOW}, false, PROCTOR_PX };

int pi = 0;

volatile State state = NEUTRAL;
Player player = nullPlayer;
bool firstLoop = true;

void setup() {
  Serial.begin(9600);
  while (!Serial) ;
  
  randomSeed(analogRead(ANALOG_SEED_PIN));
  pinMode(LED, OUTPUT);
  pinMode(PROCTOR, INPUT_PULLUP);

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
    delay(1000);
    firstLoop = false;
    
    Serial.println("GameBuzzer");
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
      Serial.println(colorToStr(players[i].color));
    }

    delay(3000);
    
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

void setState(State s) {
  switch (s) {
    case NEUTRAL:
      setColor(WHITE);
      Serial.println("State: " + stateToStr(s));
      break;
    case READY:
      shufflePlayers(players, shuffle);
      
      for (int i = 0; i < MAX_PLAYERS; i++) {
        Serial.println(colorToStr(shuffle[i].color));
      }
  
      delay(3000);
      
      setColor(GREEN);
      Serial.println("State: " + stateToStr(s));
      break;
    case BUZZED:
      startRainbowVomit();
      delay(RBV_CYCLE);
      stopRainbowVomit();
      setColor(player.color);
      Serial.println(colorToStr(player.color) + " player buzzed in");
      break;
    case TEST:
      startRainbowVomit();
      Serial.println("In Test mode");
      break;
  }
  
  state = s;
}

void setPressedEarlys() {
  for (int i = 0; i < MAX_PLAYERS; i++) {
    shuffle[i].debounce.update();
    shuffle[i].pressedEarly = shuffle[i].debounce.justPressed();
  }
}

void checkProctor() {
  proctor.debounce.update();
    
  if (proctor.debounce.justReleased()) {
    if (state == NEUTRAL) setState(READY);
    else if (state == BUZZED) setState(NEUTRAL);
  }

  delay(ADA_DEB_DELAY);
}

Player checkButtons() {
  for (int i = 0; i < MAX_PLAYERS; i++) {
    shuffle[i].debounce.update();
    
    if (shuffle[i].pressedEarly) {
      Serial.println(colorToStr(shuffle[i].color) + " pressed early");
      if (shuffle[i].debounce.justReleased()) shuffle[i].pressedEarly = false;
    }
    else if (shuffle[i].debounce.justPressed()) return shuffle[i];
  }
  
  return nullPlayer;
}

String lastTestLog = "";

void testLoop() {
  bool tripped = false;
  String msg = "";

  proctor.debounce.update();

  if (proctor.debounce.justPressed() || !digitalRead(proctor.pin)) {
    msg += " proctor";
    setPixel(proctor.pixel, proctor.color);
    tripped = true;
  }
  else setPixel(proctor.pixel, COLOR_OFF);

  for (int i = 0; i < MAX_PLAYERS; i++) {
    players[i].debounce.update();
    if (players[i].debounce.justPressed() || !digitalRead(players[i].pin)) {
      msg += " p" + String(i + 1) + ":" + String(players[i].pin);
      setPixel(players[i].pixel, players[i].color);
      tripped = true;
    } 
    else setPixel(players[i].pixel, COLOR_OFF);
  }
  
  if (!tripped) msg = "None";
  
  if (msg != lastTestLog) {
    lastTestLog = msg;
    Serial.println(msg);
  }
  
  delay(ADA_DEB_DELAY);
}
