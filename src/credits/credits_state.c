#include "credits_state.h"

#include "credits_background.h"

#include "../myLib.h"
#include "../state.h"

void goToCredits() {
  state = CREDITS;

  copyBackgroundPalette(credits_backgroundPal, credits_backgroundPalLen);
  copyTileMap(0, credits_backgroundMap, credits_backgroundMapLen);
  copyTileImages(1, credits_backgroundTiles, credits_backgroundTilesLen);
}
void credits() {
  hideSprites();

  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToStart();
  }
}
