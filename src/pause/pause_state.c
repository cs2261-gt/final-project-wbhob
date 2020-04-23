#include "pause_state.h"

#include "pause_background.h"

#include "../sound/pauseSong.h"
#include "../sound/sound.h"

#include "../myLib.h"
#include "../state.h"

void goToPause() {
  state = PAUSE;

  REG_BG0HOFF = 0;

  copyBackgroundPalette(pauseBackgroundPal, pauseBackgroundPalLen);
  copyTileMap(0, pauseBackgroundMap, pauseBackgroundMapLen);
  copyTileImages(1, pauseBackgroundTiles, pauseBackgroundTilesLen);

  pauseSound();

  REG_BG0CNT = BG_SCREENBLOCK(0) | BG_CHARBLOCK(1) | BG_SIZE_SMALL | BG_4BPP |
               BG_SIZE_WIDE;

  playSoundB(&pauseSong, PAUSESONGLEN, 1);
}

void pause() {
  REG_BG0HOFF = 0;
  hideSprites();
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    unpauseSound();
    stopSoundB();
    backToGame();
  }
  if (BUTTON_PRESSED(BUTTON_B)) {
    goToStart();
  }
}
