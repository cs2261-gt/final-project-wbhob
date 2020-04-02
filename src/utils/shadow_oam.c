#include "shadow_oam.h"

#include "../myLib.h"

void copyShadowOAM() { DMANow(3, &shadowOAM, OAM, 128); }