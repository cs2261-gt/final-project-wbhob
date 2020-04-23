#include "win_state.h"

#include "win_background.h"

#include "../sound/sound.h"

#include "../sound/startSong.h"
#include "../sound/winSong.h"

#include "../myLib.h"
#include "../state.h"

void goToWin() {
  state = WIN;

  REG_BG0CNT  = BG_SCREENBLOCK(0) | BG_CHARBLOCK(1) | BG_SIZE_SMALL | BG_4BPP;
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
    playSoundA(&startSong, STARTSONGLEN, 1);
    goToStart();
  }
}
