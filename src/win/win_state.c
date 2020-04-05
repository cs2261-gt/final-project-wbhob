#include "win_state.h"

#include "win_background.h"

#include "../myLib.h"
#include "../state.h"

void goToWin() {
  state = WIN;

  REG_BG0HOFF = 0;

  copyBackgroundPalette(winBackgroundPal, winBackgroundPalLen);
  copyTileMap(0, winBackgroundMap, winBackgroundMapLen);
  copyTileImages(1, winBackgroundTiles, winBackgroundTilesLen);
}
void win() {
  hideSprites();
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToStart();
  }
}
