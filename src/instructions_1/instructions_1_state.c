#include "instructions_1_state.h"

#include "../myLib.h"
#include "../state.h"

void goToInstructions1() {
  state = INSTRUCTIONS_1;

  hideSprites();

  // copyBackgroundPalette(instructions1BackgroundPal,
  //                       instructions1BackgroundPalLen);
  // copyTileImages(0, instructions1BackgroundTiles,
  //                instructions1BackgroundTilesLen);
  // copyTileMap(24, instructions1BackgroundMap, instructions1BackgroundMapLen);
}
void instructions1() {
  waitForVBlank();
  if (BUTTON_PRESSED(BUTTON_START)) {
    // goToStart();
  }
}
