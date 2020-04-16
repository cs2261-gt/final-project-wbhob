#include "pause_state.h"

#include "pause_background.h"

#include "../myLib.h"
#include "../state.h"

void goToPause() {
  state = PAUSE;

  REG_BG0HOFF = 0;

  copyBackgroundPalette(pauseBackgroundPal, pauseBackgroundPalLen);
  copyTileMap(0, pauseBackgroundMap, pauseBackgroundMapLen);
  copyTileImages(1, pauseBackgroundTiles, pauseBackgroundTilesLen);
}
void pause() {
  REG_BG0HOFF=0;
  hideSprites();
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToGame1();
  }
  if (BUTTON_PRESSED(BUTTON_B)) {
    goToStart();
  }
}