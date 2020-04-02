#include "myLib.h"

#include "start/start_state.h"
#include "state.h"

#include "utils/shadow_oam.h"

unsigned short buttons;
unsigned short oldButtons;

int seed;

void initialize() {
  REG_DISPCTL = MODE0 | BG0_ENABLE | SPRITE_ENABLE;

  buttons = BUTTONS;

  goToStart();
}

int main() {
  initialize();

  while (1) {
    oldButtons = buttons;
    buttons    = BUTTONS;

    stateMachine();

    copyShadowOAM();
  }
}