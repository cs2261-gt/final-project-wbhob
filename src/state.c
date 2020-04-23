#include "state.h"

#include "game_1/game_1_state.h"
#include "game_2/game_2_state.h"
#include "game_3/game_3_state.h"
#include "instructions_1/instructions_1_state.h"
#include "lose/lose_state.h"
#include "pause/pause_state.h"
#include "start/start_state.h"
#include "win/win_state.h"

int state;
int lastLevel = GAME_LEVEL_1;

void stateMachine() {
  switch (state) {
  case START:
    start();
    break;
  case PAUSE:
    pause();
    break;
  case INSTRUCTIONS_1:
    instructions1();
    break;
  case GAME_LEVEL_1:
    lastLevel = GAME_LEVEL_1;
    game1();
    break;
  case GAME_LEVEL_2:
    lastLevel = GAME_LEVEL_2;
    game2();
    break;
  case GAME_LEVEL_3:
    lastLevel = GAME_LEVEL_3;
    game3();
    break;
  case WIN:
    win();
    break;
  case LOSE:
    lose();
    break;
  }
}

void backToGame() {
  switch (lastLevel) {
  case GAME_LEVEL_1:
    goToGame1();
    break;
  case GAME_LEVEL_2:
    goToGame2();
    break;
  case GAME_LEVEL_3:
    goToGame3();
    break;
  }
}