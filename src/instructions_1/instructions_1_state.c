#include "instructions_1_state.h"

#include "instructions_1_background.h"

#include "../myLib.h"
#include "../state.h"

void goToInstructions1() {
  state = INSTRUCTIONS_1;

  copyBackgroundPalette(instructions1BackgroundPal,
                        instructions1BackgroundPalLen);
  copyTileMap(0, instructions1BackgroundMap, instructions1BackgroundMapLen);
  copyTileImages(1, instructions1BackgroundTiles,
                 instructions1BackgroundTilesLen);
}
void instructions1() {
  hideSprites();

  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToStart();
  }
}
