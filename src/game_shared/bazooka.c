#include "bazooka.h"

#include "sprites.h"

void initializeBazooka(SPRITE *bazooka) {
  bazooka->active = FALSE;
  bazooka->cdel   = -2;
  bazooka->height = 8;
  bazooka->width  = 16;
}

void fireBazooka(SPRITE *bazooka, GAMESPRITE *player) {
  if (!bazooka->active) {
    bazooka->active    = TRUE;
    bazooka->screenCol = player->screenCol;
    bazooka->screenRow = player->screenRow + player->height / 2 - bazooka->height;
  }
}

void updateBazooka(SPRITE *bazooka) {
  if (bazooka->active) {
    bazooka->screenCol += bazooka->cdel;
    if (bazooka->screenCol <= 0) {
      bazooka->active = FALSE;
    }
  }
}

void drawBazooka(SPRITE *bazooka, int index) {
  if (bazooka->active) {
    shadowOAM[index].attr0 = BAZOOKA_ATTR0 | bazooka->screenRow;
    shadowOAM[index].attr1 = BAZOOKA_ATTR1 | bazooka->screenCol;
    shadowOAM[index].attr2 = BAZOOKA_ATTR2;
  } else {
    shadowOAM[index].attr0 = ATTR0_HIDE;
  }
}

void handleBazookaCollisions(GAMESPRITE *enemies, SPRITE *bazooka, int *enemiesDestroyed, int ENEMY_COUNT, int columns) {
  if (!bazooka->active)
    return;

  for (int i = 0; i < ENEMY_COUNT; i++) {
    GAMESPRITE *enemy = &enemies[i];

    if (!enemy->active)
      continue;

    int missileHitEnemy = collision(enemy->screenCol, enemy->screenRow, enemy->width, enemy->height, bazooka->screenCol, bazooka->screenRow,
                                    bazooka->width, bazooka->height);

    if (missileHitEnemy) {
      bazooka->active = FALSE;

      destroyEnemy(enemy, enemiesDestroyed);

      int laneAbove = enemy->lane - 1;
      int lane      = enemy->lane;
      int laneBelow = enemy->lane + 1;

      int columnLeft  = enemy->columnLane - 1;
      int column      = enemy->columnLane;
      int columnRight = enemy->columnLane + 1;

      // TOP ROW
      if (laneAbove >= 0) {
        // left
        if (columnLeft >= 0) {
          GAMESPRITE *topLeftEnemy = &enemies[OFFSET(columnLeft, laneAbove, columns)];
          destroyEnemy(topLeftEnemy, enemiesDestroyed);
        }

        // center
        GAMESPRITE *topCenterEnemy = &enemies[OFFSET(column, laneAbove, columns)];
        destroyEnemy(topCenterEnemy, enemiesDestroyed);

        // right
        if (columnRight < columns) {
          GAMESPRITE *topRightEnemy = &enemies[OFFSET(columnRight, laneAbove, columns)];
          destroyEnemy(topRightEnemy, enemiesDestroyed);
        }
      }

      // left
      if (columnLeft >= 0) {
        GAMESPRITE *leftEnemy = &enemies[OFFSET(columnLeft, lane, columns)];
        destroyEnemy(leftEnemy, enemiesDestroyed);
      }

      // in front
      if (columnRight < columns) {
        GAMESPRITE *rightEnemy = &enemies[OFFSET(columnRight, lane, columns)];
        destroyEnemy(rightEnemy, enemiesDestroyed);
      }

      // BOTTOM
      if (laneBelow <= 3) {
        // left
        if (columnLeft >= 0) {
          GAMESPRITE *bottomLeftEnemy = &enemies[OFFSET(columnLeft, laneBelow, columns)];
          destroyEnemy(bottomLeftEnemy, enemiesDestroyed);
        }
        // directly below
        GAMESPRITE *belowCenterEnemy = &enemies[OFFSET(column, laneBelow, columns)];
        destroyEnemy(belowCenterEnemy, enemiesDestroyed);
        // right
        if (columnRight < columns) {
          GAMESPRITE *bottomRightEnemy = &enemies[OFFSET(columnRight, laneBelow, columns)];
          destroyEnemy(bottomRightEnemy, enemiesDestroyed);
        }
      }

      return;
    }
  }
}

void destroyEnemy(GAMESPRITE *enemy, int *enemiesDestroyed) {
  if (!enemy->active)
    return;

  enemy->active = FALSE;
  enemy->health = 0;
  (*enemiesDestroyed)++;
}