#ifndef GAME_1_STATE_H
#define GAME_1_STATE_H

void goToGame1();
void game1();

#define PLAYER_INITIAL_HEALTH_COUNT 7
#define ENEMY_INITIAL_HEALTH_COUNT 7

#define ENEMY_COUNT 8
#define PLAYER_BULLET_COUNT 10
#define ENEMY_BULLET_COUNT 10

/**********************
 * OAM Partitions
 **********************/
#define PLAYER_OAM_SIZE 1
#define PLAYER_OAM_INDEX 0

#define BAZOOKA_OAM_SIZE 1
#define BAZOOKA_OAM_INDEX ((PLAYER_OAM_SIZE) + (PLAYER_OAM_INDEX))

#define ENEMY_HEALTH_OAM_SIZE ENEMY_COUNT
#define ENEMY_HEALTH_OAM_INDEX ((BAZOOKA_OAM_SIZE) + (BAZOOKA_OAM_INDEX))

#define ENEMY_BULLET_OAM_SIZE ENEMY_BULLET_COUNT
#define ENEMY_BULLET_OAM_INDEX                                                 \
  ((ENEMY_HEALTH_OAM_SIZE) + (ENEMY_HEALTH_OAM_INDEX))

#define HEALTH_OAM_SIZE PLAYER_INITIAL_HEALTH_COUNT
#define HEALTH_OAM_INDEX ((ENEMY_BULLET_OAM_SIZE) + (ENEMY_BULLET_OAM_INDEX))

#define ENEMY_OAM_SIZE ENEMY_COUNT
#define ENEMY_OAM_INDEX ((HEALTH_OAM_SIZE) + (HEALTH_OAM_INDEX))

#define PLAYER_BULLET_OAM_SIZE PLAYER_BULLET_COUNT
#define PLAYER_BULLET_OAM_INDEX ((ENEMY_OAM_SIZE) + (ENEMY_OAM_INDEX))


// computed by hand using algebra... may have to refactor if the map changes


#endif
