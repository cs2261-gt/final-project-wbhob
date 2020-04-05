#include "sprites.h"

#include "spritesheet.h"

void copySpriteSheet() {
  DMANow(3, &spritesheetPal, SPRITEPALETTE, spritesheetPalLen / 2);
  DMANow(3, &spritesheetTiles, &CHARBLOCK[4], spritesheetTilesLen / 2);
}