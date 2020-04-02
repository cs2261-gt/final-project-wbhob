#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H

void copyBackgroundPalette(unsigned short palette[], int length);
void copyTileImages(unsigned short charblock, unsigned short tiles[], int tilesLength);
void copyTileMap(unsigned short screenblock, unsigned short tileMap[], int mapLength);

#endif