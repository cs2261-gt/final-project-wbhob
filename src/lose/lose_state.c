#include "lose_state.h"

#include "../myLib.h"
#include "../state.h"

void goToLose() {
  state = LOSE;

  hideSprites();

  // copyBackgroundPalette(loseBackgroundPal, loseBackgroundPalLen);
  // copyTileImages(0, loseBackgroundTiles, loseBackgroundTilesLen);
  // copyTileMap(24, loseBackgroundMap, loseBackgroundMapLen);
}
void lose() {
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    // goToStart();
  }
}
