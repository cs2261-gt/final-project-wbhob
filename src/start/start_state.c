#include "start_state.h"

#include "../utils/backgrounds.h"
#include "start_background.h"

#include "../myLib.h"
#include "../state.h"

OBJ_ATTR player;

void goToStart() {
  state = START;

  hideSprites();

  REG_BG0CNT = BG_SCREENBLOCK(0) | BG_CHARBLOCK(1) | BG_SIZE_SMALL | BG_4BPP;

  copyBackgroundPalette(startBackgroundPal, startBackgroundPalLen);
  copyTileImages(1, startBackgroundTiles, startBackgroundTilesLen);
  copyTileMap(0, startBackgroundMap, startBackgroundMapLen);
}

void start() {
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    // goToStart();
  }
}
