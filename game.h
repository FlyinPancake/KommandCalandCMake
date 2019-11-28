//
// Created by flyinpancake on 26/11/2019.
//

#ifndef KOMMANDCALAND_GAME_H
#define KOMMANDCALAND_GAME_H

#include "item.h"

typedef struct Save {
    int x,y;
    item *inv;
} Save;

void saveGame(int savNo, int x, int y, item *inv);
void play(int savNo);
#endif //KOMMANDCALAND_GAME_H
