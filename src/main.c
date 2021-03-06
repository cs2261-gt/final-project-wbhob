/*************************
 * ORIGINAL MUSIC: https://soundcloud.com/wbhob/sets/gameboy-advanced
 *
 *
 * FINISHED
 *  - Can move through game states
 *  - Enemy and Player healths
 *  - Enemy and player deaths
 *  - Sound (looping - game music, non-looping - lose sound)
 *    - the music is all original, by the way :) and covers of existing songs
 *  - Backgrounds
 *  - XXL background (3rd level of game)
 *  - Sprites
 *  - Animations - the robot's treads and the player health indicators are
 *    looping animations
 *  - gun/bazooka sounds
 *  - cheat (bazooka, activated by pressing LEFT, RIGHT, LEFT, RIGHT, LEFT, RIGHT, LEFT, RIGHT)
 *
 * OUTSTANDING TASKS
 *  - All done :)
 *
 * KNOWN ISSUES
 *  - None that I know of
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
 * TECHNICAL THING :
 *   In order to infinitely scroll the background without going out of memory
 * for XL, I loaded the tilemap in TWICE, and once we go past the fourth
 * consecutive screenblock, we just go back to the first one.
 *
 */

#include "myLib.h"

#include "start/start_state.h"
#include "state.h"

#include "sound/sound.h"
#include "sound/startSong.h"

#include "utils/shadow_oam.h"

unsigned short buttons;
unsigned short oldButtons;

int seed;
int cheat = FALSE;

void initialize() {
  REG_DISPCTL = MODE0 | BG0_ENABLE | SPRITE_ENABLE;

  buttons = BUTTONS;

  copySpriteSheet();

  setupSounds();
  setupInterrupts();

  playSoundA(&startSong, STARTSONGLEN, 1);

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