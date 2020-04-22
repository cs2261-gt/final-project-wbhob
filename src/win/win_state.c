#include "win_state.h"

#include "win_background.h"

#include "../sound/sound.h"
#include "../sound/winSong.h"

#include "../myLib.h"
#include "../state.h"

void goToWin() {
  state = WIN;

  REG_BG0HOFF = 0;

  copyBackgroundPalette(winBackgroundPal, winBackgroundPalLen);
  copyTileMap(0, winBackgroundMap, winBackgroundMapLen);
  copyTileImages(1, winBackgroundTiles, winBackgroundTilesLen);

  playSoundA(&winSong, WINSONGLEN, 0);
}
void win() {
  hideSprites();
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToStart();
  }
}
