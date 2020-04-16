#include "backgrounds.h"

#include "../myLib.h"

void copyBackgroundPalette(u16 palette[], int length) {
  DMANow(3, palette, PALETTE, length / 2);
}

void copyTileImages(u16 charBlock, u16 tiles[], int tilesLength) {
  DMANow(3, tiles, &CHARBLOCK[charBlock], tilesLength / 2);
}

void copyTileMap(u16 screenBlock, u16 tileMap[], int mapLength) {
  DMANow(3, tileMap, &SCREENBLOCK[screenBlock], mapLength / 2);
}