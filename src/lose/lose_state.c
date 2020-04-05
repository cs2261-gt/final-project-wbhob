#include "lose_state.h"

#include "lose_background.h"

#include "../myLib.h"
#include "../state.h"

void goToLose() {
  state = LOSE;

  REG_BG0HOFF = 0;

  copyBackgroundPalette(loseBackgroundPal, loseBackgroundPalLen);
  copyTileMap(0, loseBackgroundMap, loseBackgroundMapLen);
  copyTileImages(1, loseBackgroundTiles, loseBackgroundTilesLen);
}
void lose() {
  hideSprites();
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToStart();
  }
}
