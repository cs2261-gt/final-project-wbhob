#include "game_3_state.h"

#include "../myLib.h"

#include "../state.h"
#include "../utils/backgrounds.h"

#include "../game_shared/sprites.h"
#include "../lose/lose_state.h"
#include "../win/win_state.h"
#include "game_3_background.h"

static GAMESPRITE player;
static GAMESPRITE enemies[ENEMY_COUNT];
static SPRITE playerBullets[PLAYER_BULLET_COUNT];
static SPRITE enemyBullets[ENEMY_BULLET_COUNT];

static int frames;
static int enemiesDestroyed;
static int hOffBg0 = 0;

static void initializePlayer() {
  player.health = PLAYER_INITIAL_HEALTH_COUNT;

  player.height = 16;
  player.width  = 16;

  player.lane = 1;

  player.screenRow = 120 - player.height;
  player.screenCol = SCREENWIDTH - player.width / 2 - 40;
}

static void initializeEnemies() {
  enemiesDestroyed = 0;
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 4; i++) {
      GAMESPRITE *enemy = &enemies[OFFSET(i, j, 4)];
      enemy->active     = TRUE;

      enemy->height = 16;
      enemy->width  = 16;

      enemy->lane = j;

      enemy->health = 5;

      enemy->numFrames    = ENEMY_NUM_FRAMES;
      enemy->aniCounter   = i % ENEMY_NUM_FRAMES;
      enemy->curFrame     = i % ENEMY_NUM_FRAMES;
      enemy->prevAniState = enemies[i].aniState - 1;

      enemy->screenRow = GAME_1_LANE(j);
      enemy->screenCol = GAME_1_ENEMY_COLUMN(i);
    }
  }
}

static void initializeBullets() {
  for (int i = 0; i < PLAYER_BULLET_COUNT; i++) {
    playerBullets[i].active = FALSE;
    playerBullets[i].cdel   = -2;
    playerBullets[i].height = 2;
    playerBullets[i].width  = 8;
  }
  for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
    enemyBullets[i].active = FALSE;
    enemyBullets[i].cdel   = 1;
    enemyBullets[i].height = 2;
    enemyBullets[i].width  = 8;
  }
}

static void drawPlayerHealth() {
  int healthRow = 8;

  for (int i = 0; i < player.health; i++) {
    int oamIndex = HEALTH_OAM_INDEX + i;

    shadowOAM[oamIndex].attr0 = HEART_ATTR0 | healthRow;
    shadowOAM[oamIndex].attr1 = HEART_ATTR1 | healthRow + (i * 16);
    shadowOAM[oamIndex].attr2 = HEART_ATTR2;
  }

  for (int i = player.health; i < PLAYER_INITIAL_HEALTH_COUNT; i++) {
    int oamIndex = HEALTH_OAM_INDEX + i;

    shadowOAM[oamIndex].attr0 = ATTR0_HIDE;
  }
}

static void drawEnemyHealth() {
  for (int i = 0; i < ENEMY_COUNT; i++) {
    GAMESPRITE enemy = enemies[i];
    int oamIndex     = ENEMY_HEALTH_OAM_INDEX + i;

    shadowOAM[oamIndex].attr0 = ENEMY_HEALTH_ATTR0 | (enemy.screenRow - 4);
    shadowOAM[oamIndex].attr1 = ENEMY_HEALTH_ATTR1 | enemy.screenCol;
    shadowOAM[oamIndex].attr2 = ENEMY_HEALTH_ATTR2(enemy.health);
  }
}

static void drawPlayer() {
  shadowOAM[PLAYER_OAM_INDEX].attr0 = PLAYER_ATTR0 | player.screenRow;
  shadowOAM[PLAYER_OAM_INDEX].attr1 = PLAYER_ATTR1 | player.screenCol;
  shadowOAM[PLAYER_OAM_INDEX].attr2 = PLAYER_ATTR2(0);
  // shadowOAM[PLAYER_OAM_INDEX].attr2 = PLAYER_ATTR2(player.curFrame);
}

static void drawEnemies() {
  for (int i = 0; i < ENEMY_COUNT; i++) {
    GAMESPRITE enemy = enemies[i];
    int oamIndex     = ENEMY_OAM_INDEX + i;

    if (enemy.active) {
      shadowOAM[oamIndex].attr0 = ENEMY_ATTR0 | enemy.screenRow;
      shadowOAM[oamIndex].attr1 = ENEMY_ATTR1 | enemy.screenCol;
      shadowOAM[oamIndex].attr2 = ENEMY_ATTR2(0);
      // shadowOAM[i].attr2 = ENEMY_ATTR2(enemy.curFrame);
    } else {
      shadowOAM[oamIndex].attr0 = ATTR0_HIDE;
    }
  }
}

static void drawPlayerBullets() {
  for (int i = 0; i < PLAYER_BULLET_COUNT; i++) {
    SPRITE bullet = playerBullets[i];
    int oamIndex  = PLAYER_BULLET_OAM_INDEX + i;
    if (bullet.active) {
      shadowOAM[oamIndex].attr0 = PLAYER_BULLET_ATTR0 | bullet.screenRow;
      shadowOAM[oamIndex].attr1 = PLAYER_BULLET_ATTR1 | bullet.screenCol;
      shadowOAM[oamIndex].attr2 = PLAYER_BULLET_ATTR2;
    } else {
      shadowOAM[oamIndex].attr0 = ATTR0_HIDE;
    }
  }
}

static void drawEnemyBullets() {
  for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
    SPRITE bullet = enemyBullets[i];
    int oamIndex  = ENEMY_BULLET_OAM_INDEX + i;
    if (bullet.active) {
      shadowOAM[oamIndex].attr0 = ENEMY_BULLET_ATTR0 | bullet.screenRow;
      shadowOAM[oamIndex].attr1 = ENEMY_BULLET_ATTR1 | bullet.screenCol;
      shadowOAM[oamIndex].attr2 = ENEMY_BULLET_ATTR2;
    } else {
      shadowOAM[oamIndex].attr0 = ATTR0_HIDE;
    }
  }
}

static void handleCollisions() {
  for (int i = 0; i < PLAYER_BULLET_COUNT; i++) {
    SPRITE bullet = playerBullets[i];
    if (bullet.active) {
      for (int j = 0; j < ENEMY_COUNT; j++) {
        GAMESPRITE *enemy = &enemies[j];
        if (enemy->active &&
            collision(bullet.screenCol, bullet.screenRow, bullet.width,
                      bullet.height, enemy->screenCol, enemy->screenRow,
                      enemy->width, enemy->height)) {
          playerBullets[i].active = FALSE;
          enemy->health--;

          if (enemy->health <= 0) {
            enemy->active = FALSE;
            enemiesDestroyed++;
          }

          break;
        }
      }
    }
  }
  for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
    SPRITE bullet = enemyBullets[i];
    if (bullet.active &&
        collision(bullet.screenCol, bullet.screenRow, bullet.width,
                  bullet.height, player.screenCol, player.screenRow,
                  player.width, player.height)) {
      enemyBullets[i].active = FALSE;
      player.health--;
      break;
    }
  }
}

static void updateBullets() {
  for (int i = 0; i < PLAYER_BULLET_COUNT; i++) {
    if (playerBullets[i].active) {
      playerBullets[i].screenCol += playerBullets[i].cdel;
      if (playerBullets[i].screenCol <= 0) {
        playerBullets[i].active = FALSE;
      }
    }
  }
  for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
    if (enemyBullets[i].active) {
      enemyBullets[i].screenCol += enemyBullets[i].cdel;
      if (enemyBullets[i].screenCol >= SCREENWIDTH) {
        enemyBullets[i].active = FALSE;
      }
    }
  }
}

static void fireEnemyBullet() {
  int enemyIndex   = rand() % ENEMY_COUNT;
  GAMESPRITE enemy = enemies[enemyIndex];
  if (enemy.active)
    for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
      if (!enemyBullets[i].active) {
        enemyBullets[i].active    = TRUE;
        enemyBullets[i].screenCol = enemy.screenCol;
        enemyBullets[i].screenRow =
            enemy.screenRow + (enemy.height / 2) - (enemyBullets[i].height / 2);
        break;
      }
    }
}

static void firePlayerBullet() {
  for (int i = 0; i < PLAYER_BULLET_COUNT; i++) {
    if (!playerBullets[i].active) {
      playerBullets[i].active    = TRUE;
      playerBullets[i].screenCol = player.screenCol;
      playerBullets[i].screenRow =
          player.screenRow + player.height / 2 - playerBullets[i].height;
      break;
    }
  }
}

static void handlePlayerInput() {
  if (BUTTON_PRESSED(BUTTON_UP) && player.lane - 1 >= 0) {
    player.lane--;
  }
  if (BUTTON_PRESSED(BUTTON_DOWN) && player.lane + 1 <= 3) {
    player.lane++;
  }
  if (BUTTON_PRESSED(BUTTON_A)) {
    firePlayerBullet();
  }
  if (BUTTON_PRESSED(BUTTON_START)) {
    goToPause();
  }
  player.screenRow = GAME_1_LANE(player.lane);
}

static void moveBackgrounds() {
  // if (frames % 2) {
  hOffBg0++;
  // }
  REG_BG0HOFF = hOffBg0;
}

void initializeGame3() {
  frames  = 0;
  hOffBg0 = 0;

  initializeBullets();
  initializeEnemies();
  initializePlayer();
}

void goToGame3() {
  state = GAME_LEVEL_3;

  REG_BG0CNT  = BG_SCREENBLOCK(0) | BG_CHARBLOCK(1) | BG_SIZE_SMALL | BG_4BPP;
  REG_BG0HOFF = hOffBg0;

  copyBackgroundPalette(game3BackgroundPal, game3BackgroundPalLen);
  copyTileMap(0, game3BackgroundMap, game3BackgroundMapLen);
  copyTileImages(1, game3BackgroundTiles, game3BackgroundTilesLen);
}

void game3() {
  frames++;
  updateBullets();
  handlePlayerInput();

  if (frames % 20 == 0) {
    fireEnemyBullet();
  }

  handleCollisions();

  waitForVBlank();

  moveBackgrounds();
  drawEnemyHealth();
  drawPlayerHealth();
  drawEnemyBullets();
  drawPlayerBullets();
  drawEnemies();
  drawPlayer();

  if (player.health == 0) {
    hideSprites();
    goToLose();
  }

  if (enemiesDestroyed == ENEMY_COUNT) {
    hideSprites();
    goToWin();
  }
}
