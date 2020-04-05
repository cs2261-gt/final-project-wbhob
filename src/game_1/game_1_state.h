#ifndef GAME_1_STATE_H
#define GAME_1_STATE_H

void goToGame1();
void game1();

#define INITIAL_HEALTH_COUNT 7

#define ENEMY_COUNT 8
#define PLAYER_BULLET_COUNT 10
#define ENEMY_BULLET_COUNT 10

/**********************
 * OAM Partitions
 **********************/
#define PLAYER_OAM_SIZE 1
#define PLAYER_OAM_INDEX 0

#define HEALTH_OAM_SIZE INITIAL_HEALTH_COUNT
#define HEALTH_OAM_INDEX ((PLAYER_OAM_SIZE) + (PLAYER_OAM_INDEX))

#define ENEMY_OAM_SIZE ENEMY_COUNT
#define ENEMY_OAM_INDEX ((HEALTH_OAM_SIZE) + (HEALTH_OAM_INDEX))

#define PLAYER_BULLET_OAM_SIZE PLAYER_BULLET_COUNT
#define PLAYER_BULLET_OAM_INDEX ((ENEMY_OAM_INDEX) + (ENEMY_OAM_SIZE))

#define ENEMY_BULLET_OAM_SIZE ENEMY_BULLET_COUNT
#define ENEMY_BULLET_OAM_INDEX                                                 \
  ((PLAYER_BULLET_OAM_SIZE) + (PLAYER_BULLET_OAM_INDEX))


// computed by hand using algebra... may have to refactor if the map changes
#define GAME_1_LANE(lane) (40 + (32 * (lane)))
#define GAME_1_ENEMY_COLUMN(slot) (20 + (32 * (slot)))

#endif
