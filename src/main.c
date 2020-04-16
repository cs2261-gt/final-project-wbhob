/*************************
 * FINISHED SO FAR
 *  - Can move through game states
 *  - Enemy and Player healths
 *  - Enemy and player deaths
 *
 * OUTSTANDING TASKS
 *  - Art
 *  - Bazooka (which I will make my cheat. It will blow up the robot it hits and
 *  every one nearby)
 *  - Parallax backgrounds or XXL background
 *  - Sound
 *
 * KNOWN ISSUES
 *  - I have not been able to find any bugs in this version (but that doesn't
 * mean there aren't any!)
 *  - One thing missing from the requirements Marie gave me is the bazooka
 *  implementation. I think it's a pretty fun and unique cheat, so I think
 *  that's what I'll do as my cheat in the next Milestone.
 *
 * GAMEPLAY INSTRUCTIONS
 *  - Press "A" to shoot.
 *  - Each robot's health is indicated by the bar floating
 *  above it.
 *  - Each level will increase the frequency of bullets and quantity of
 *  robots, and will advance automatically once all the robots on the screen are
 *  dead.
 *
 *
 *
 */

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

  copySpriteSheet();

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