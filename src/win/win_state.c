#include "win_state.h"

#include "../myLib.h"
#include "../state.h"

void goToWin() {
  state = WIN;

  hideSprites();

  // copyBackgroundPalette(winBackgroundPal, winBackgroundPalLen);
  // copyTileImages(0, winBackgroundTiles, winBackgroundTilesLen);
  // copyTileMap(24, winBackgroundMap, winBackgroundMapLen);
}
void win() {
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    // goToStart();
  }
}
