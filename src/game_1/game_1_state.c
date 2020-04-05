#include "game_1_state.h"

#include "../myLib.h"
#include "../state.h"
#include "../utils/backgrounds.h"

#include "../game_shared/sprites.h"
#include "../lose/lose_state.h"
#include "../win/win_state.h"
#include "game_1_background.h"

GAMESPRITE player;
GAMESPRITE enemies[ENEMY_COUNT];
SPRITE playerBullets[PLAYER_BULLET_COUNT];
SPRITE enemyBullets[ENEMY_BULLET_COUNT];

int frames;
int enemiesDestroyed;
int hOffBg0 = 0;
int health;

static void initializePlayer() {
  health = INITIAL_HEALTH_COUNT;

  player.height = 16;
  player.width  = 16;

  player.lane = 1;

  player.screenRow = 120 - player.height;
  player.screenCol = SCREENWIDTH - player.width / 2 - 40;
}

static void initializeEnemies() {
  enemiesDestroyed = 0;
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 2; i++) {
      enemies[OFFSET(i, j, 2)].active = TRUE;

      enemies[OFFSET(i, j, 2)].height = 16;
      enemies[OFFSET(i, j, 2)].width  = 16;

      enemies[OFFSET(i, j, 2)].lane = j;

      enemies[OFFSET(i, j, 2)].numFrames    = ENEMY_NUM_FRAMES;
      enemies[OFFSET(i, j, 2)].aniCounter   = i % ENEMY_NUM_FRAMES;
      enemies[OFFSET(i, j, 2)].curFrame     = i % ENEMY_NUM_FRAMES;
      enemies[OFFSET(i, j, 2)].prevAniState = enemies[i].aniState - 1;

      enemies[OFFSET(i, j, 2)].screenRow = GAME_1_LANE(j);
      enemies[OFFSET(i, j, 2)].screenCol = GAME_1_ENEMY_COLUMN(i);
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

static void drawHealth() {
  int healthRow = 8;

  for (int i = 0; i < health; i++) {
    int oamIndex = HEALTH_OAM_INDEX + i;

    shadowOAM[oamIndex].attr0 = HEART_ATTR0 | healthRow;
    shadowOAM[oamIndex].attr1 = HEART_ATTR1 | healthRow + (i * 16);
    shadowOAM[oamIndex].attr2 = HEART_ATTR2;
  }

  for (int i = health; i < INITIAL_HEALTH_COUNT; i++) {
    int oamIndex = HEALTH_OAM_INDEX + i;

    shadowOAM[oamIndex].attr0 = ATTR0_HIDE;
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
        GAMESPRITE enemy = enemies[j];
        if (enemy.active &&
            collision(bullet.screenCol, bullet.screenRow, bullet.width,
                      bullet.height, enemy.screenCol, enemy.screenRow,
                      enemy.width, enemy.height)) {
          playerBullets[i].active = FALSE;
          enemies[j].active       = FALSE;
          enemiesDestroyed++;
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
      health--;
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
            enemy.screenRow + enemy.height / 2 - enemyBullets[i].height / 2;
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

void initializeGame() {
  frames  = 0;
  hOffBg0 = 0;

  initializeBullets();
  initializeEnemies();
  initializePlayer();
}

void goToGame1() {
  state = GAME_LEVEL_1;

  REG_BG0CNT = BG_SCREENBLOCK(0) | BG_CHARBLOCK(1) | BG_SIZE_SMALL | BG_4BPP;
  REG_BG0HOFF = hOffBg0;

  copyBackgroundPalette(game1BackgroundPal, game1BackgroundPalLen);
  copyTileMap(0, game1BackgroundMap, game1BackgroundMapLen);
  copyTileImages(1, game1BackgroundTiles, game1BackgroundTilesLen);
}

void game1() {
  frames++;
  updateBullets();
  handlePlayerInput();

  if (frames % 30 == 0) {
    fireEnemyBullet();
  }

  handleCollisions();

  waitForVBlank();

  moveBackgrounds();
  drawHealth();
  drawEnemyBullets();
  drawPlayerBullets();
  drawEnemies();
  drawPlayer();

  if (health == 0) {
    goToLose();
  }

  if (enemiesDestroyed == ENEMY_COUNT) {
    goToWin();
  }
}
