#ifndef BAZOOKA_H
#define BAZOOKA_H

#include "../myLib.h"

void initializeBazooka(SPRITE *);
void fireBazooka(SPRITE *, GAMESPRITE *);
void updateBazooka(SPRITE *);
void drawBazooka(SPRITE *, int);

void handleBazookaCollisions(GAMESPRITE *, SPRITE *, int *, int, int);
void destroyEnemy(GAMESPRITE *, int *);

#endif