#ifndef STATE_H
#define STATE_H

void stateMachine();

enum { START, INSTRUCTIONS_1, GAME_LEVEL_1, WIN, LOSE };

extern int state;

#endif
