#include "sprites.h"

#include "spritesheet.h"

#include "../utils/shadow_oam.h"

static int healthCurFrame   = 0;
static int healthTotalFrame = 5;

void copySpriteSheet() {
  DMANow(3, &spritesheetPal, SPRITEPALETTE, spritesheetPalLen / 2);
  DMANow(3, &spritesheetTiles, &CHARBLOCK[4], spritesheetTilesLen / 2);
}

void updateEnemy(GAMESPRITE *enemy, int size) {
  enemy->aniCounter++;
  if (enemy->aniCounter % 4)
    enemy->curFrame = enemy->aniCounter / 4 % enemy->numFrames;
}

void drawPlayerHealth(int health, int initialHealth, int frames, u16 oamPartitionStart) {
  int healthRow = 8;
  if (frames % 10 == 0) {
    healthCurFrame++;
    if (healthCurFrame >= healthTotalFrame -1 ) {
      healthCurFrame = 0;
    }
  }
  for (int i = 0; i < health; i++) {
    int oamIndex = oamPartitionStart + i;

    shadowOAM[oamIndex].attr0 = HEART_ATTR0 | healthRow;
    shadowOAM[oamIndex].attr1 = HEART_ATTR1 | healthRow + (i * 16);
    shadowOAM[oamIndex].attr2 = HEART_ATTR2(healthCurFrame);
  }

  for (int i = health; i < initialHealth; i++) {
    int oamIndex = oamPartitionStart + i;

    shadowOAM[oamIndex].attr0 = ATTR0_HIDE;
  }
}