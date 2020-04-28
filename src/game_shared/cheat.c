#include "cheat.h"

u16 cheatSequence[CHEAT_SEQUENCE_LENGTH] = {
    BUTTON_LEFT, BUTTON_RIGHT, BUTTON_LEFT, BUTTON_RIGHT, BUTTON_LEFT, BUTTON_RIGHT, BUTTON_LEFT, BUTTON_RIGHT,
};

u16 buttonList[CHEAT_SEQUENCE_LENGTH];

void recordButtonPresses() {
  if (BUTTON_PRESSED(BUTTON_UP))
    push(BUTTON_UP);

  if (BUTTON_PRESSED(BUTTON_DOWN))
    push(BUTTON_DOWN);

  if (BUTTON_PRESSED(BUTTON_LEFT))
    push(BUTTON_LEFT);

  if (BUTTON_PRESSED(BUTTON_RIGHT))
    push(BUTTON_RIGHT);

  if (BUTTON_PRESSED(BUTTON_A))
    push(BUTTON_A);

  if (BUTTON_PRESSED(BUTTON_B))
    push(BUTTON_B);

  if (BUTTON_PRESSED(BUTTON_START))
    push(BUTTON_START);
}

void push(u16 data) {
  for (int i = 0; i < CHEAT_SEQUENCE_LENGTH - 1; i++) {
    buttonList[i] = buttonList[i + 1];
  }
  buttonList[CHEAT_SEQUENCE_LENGTH - 1] = data;
}

int checkCheatSequence() {
  recordButtonPresses();

  for (int i = 0; i < CHEAT_SEQUENCE_LENGTH; i++) {
    if (cheatSequence[i] != buttonList[i]) {
      return FALSE;
    }
  }

  return TRUE;
}
