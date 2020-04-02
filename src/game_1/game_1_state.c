#include "game_1_state.h"

#include "../myLib.h"
#include "../state.h"

void goToGame1() {
  state = GAME_LEVEL_1;

  hideSprites();

  // copyBackgroundPalette(game1BackgroundPal, game1BackgroundPalLen);
  // copyTileImages(0, game1BackgroundTiles, game1BackgroundTilesLen);
  // copyTileMap(24, game1BackgroundMap, game1BackgroundMapLen);
}
void game1() {
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    // goToStart();
  }
}
