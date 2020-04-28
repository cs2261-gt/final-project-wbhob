#include "enemies.h"

#include "sprites.h"

void initializeEnemies(GAMESPRITE *enemies, int columns) {
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < columns; i++) {
      GAMESPRITE *enemy = &enemies[OFFSET(i, j, columns)];

      enemy->active = TRUE;

      enemy->height = 16;
      enemy->width  = 16;

      enemy->columnLane = i;
      enemy->lane       = j;

      enemy->health = 5;

      enemy->numFrames  = ENEMY_NUM_FRAMES;
      enemy->aniCounter = i % ENEMY_NUM_FRAMES;
      enemy->curFrame   = i % ENEMY_NUM_FRAMES;

      enemy->screenRow = LANE(j);
      enemy->screenCol = ENEMY_COLUMN(i);
    }
  }
}