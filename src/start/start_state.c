#include "start_state.h"

#include "../game_1/game_1_state.h"
#include "../game_shared/sprites.h"
#include "../instructions_1/instructions_1_state.h"
#include "../utils/backgrounds.h"
#include "start_background.h"


#include "../myLib.h"
#include "../state.h"

ANISPRITE player;
DOOR startDoor, instructionsDoor, somethingElseDoor;

static int doorCollision(DOOR door) {
  return collision(player.screenCol, player.screenRow, player.width,
                   player.height, door.col, door.row, door.width, door.height);
}

static void initializePlayer() {

  player.height = 16;
  player.width  = 16;

  player.screenRow = 138 - player.height;
  player.screenCol = SCREENWIDTH / 2 - player.width / 2;

  player.cdel = 1;
  player.rdel = 1;
}

static void initializeDoors() {
  int doorWidth  = 32;
  int doorHeight = 32;
  int doorRow    = 108;

  startDoor.width  = doorWidth;
  startDoor.height = doorHeight;
  startDoor.col    = 104;
  startDoor.row    = doorRow;

  instructionsDoor.width  = doorWidth;
  instructionsDoor.height = doorHeight;
  instructionsDoor.col    = 24;
  instructionsDoor.row    = doorRow;

  somethingElseDoor.width  = doorWidth;
  somethingElseDoor.height = doorHeight;
  somethingElseDoor.col    = 184;
  somethingElseDoor.row    = doorRow;
}

static void handlePlayerMovement() {
  if (BUTTON_HELD(BUTTON_LEFT) && player.screenCol - player.cdel > 0) {
    player.screenCol -= player.cdel;
  }
  if (BUTTON_HELD(BUTTON_RIGHT) &&
      player.screenCol + player.width + player.cdel < SCREENWIDTH) {
    player.screenCol += player.cdel;
  }
}

static void handlePlayerSelection() {
  if (BUTTON_PRESSED(BUTTON_START)) {
    if (doorCollision(startDoor)) {
      initializeGame();
      goToGame1();
    } else if (doorCollision(instructionsDoor)) {
      goToInstructions1();
    } else if (doorCollision(somethingElseDoor)) {
      // do something else???
    }
  }
}

static void drawPlayer() {
  shadowOAM[0].attr0 = PLAYER_ATTR0 | player.screenRow;
  shadowOAM[0].attr1 = PLAYER_ATTR1 | player.screenCol;
  shadowOAM[0].attr2 = PLAYER_ATTR2(0);
}

void goToStart() {
  state = START;

  hideSprites();

  REG_BG0CNT = BG_SCREENBLOCK(0) | BG_CHARBLOCK(1) | BG_SIZE_SMALL | BG_4BPP;

  copyBackgroundPalette(startBackgroundPal, startBackgroundPalLen);
  copyTileMap(0, startBackgroundMap, startBackgroundMapLen);
  copyTileImages(1, startBackgroundTiles, startBackgroundTilesLen);

  initializeDoors();
  initializePlayer();
}

void start() {
  handlePlayerMovement();
  handlePlayerSelection();

  waitForVBlank();

  drawPlayer();
}