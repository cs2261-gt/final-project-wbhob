#ifndef SPRITES_H
#define SPRITES_H

#include "../myLib.h"

void copySpriteSheet();
void drawPlayerHealth(int health, int initialHealth, int frames, u16 oamPartitionStart);

#define CHEAT_SEQUENCE_LENGTH 11

#define LANE(lane) (40 + (32 * (lane)))
#define ENEMY_COLUMN(slot) (20 + (32 * (slot)))

/******************************
 * Player Sprite Macros
 ****************************/
#define PLAYER_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_SQUARE)
#define PLAYER_ATTR1 (ATTR1_SMALL)
#define PLAYER_ATTR2(frame) (ATTR2_PALROW(0) | ATTR2_TILEID((frame), 2))

#define PLAYER_BULLET_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_SQUARE)
#define PLAYER_BULLET_ATTR1 (ATTR1_TINY)
#define PLAYER_BULLET_ATTR2 (ATTR2_PALROW(0) | ATTR2_TILEID(0, 6))

#define BAZOOKA_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_WIDE)
#define BAZOOKA_ATTR1 (ATTR1_TINY)
#define BAZOOKA_ATTR2 (ATTR2_PALROW(0) | ATTR2_TILEID(0, 9))

/******************************
 * Enemy Sprite Macros
 ****************************/
#define ENEMY_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_SQUARE)
#define ENEMY_ATTR1 (ATTR1_SMALL)
#define ENEMY_ATTR2(frame) (ATTR2_PALROW(0) | ATTR2_TILEID(frame * 2, 4))

#define ENEMY_BULLET_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_SQUARE)
#define ENEMY_BULLET_ATTR1 (ATTR1_TINY)
#define ENEMY_BULLET_ATTR2 (ATTR2_PALROW(0) | ATTR2_TILEID(1, 6))

#define ENEMY_HEALTH_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_WIDE)
#define ENEMY_HEALTH_ATTR1 (ATTR1_TINY)
#define ENEMY_HEALTH_ATTR2(health) (ATTR2_PALROW(1) | ATTR2_TILEID((5 - (health)) * 2, 8))

/******************************
 * General Macros
 ****************************/
#define HEART_ATTR0 (ATTR0_REGULAR | ATTR0_4BPP | ATTR0_WIDE)
#define HEART_ATTR1 (ATTR1_SMALL)
#define HEART_ATTR2(frame) (ATTR2_PALROW(0) | ATTR2_TILEID(frame * 2, 7))

#define ENEMY_NUM_FRAMES 3

#endif