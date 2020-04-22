#include "lose_state.h"

#include "lose_background.h"

#include "../sound/loseSong.h"
#include "../sound/sound.h"

#include "../myLib.h"
#include "../state.h"

void goToLose() {
  state = LOSE;

  REG_BG0HOFF = 0;

  copyBackgroundPalette(loseBackgroundPal, loseBackgroundPalLen);
  copyTileMap(0, loseBackgroundMap, loseBackgroundMapLen);
  copyTileImages(1, loseBackgroundTiles, loseBackgroundTilesLen);

  playSoundA(&loseSong, LOSESONGLEN, 0);
}
void lose() {
  hideSprites();
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToStart();
  }
}
