//
// Created by flyinpancake on 17/11/2019.
//

#ifndef KOMMANDCALAND_ROOM_H
#define KOMMANDCALAND_ROOM_H

#include <stdbool.h>
#include "chapter.h"
#include "movement.h"

bool actionSuccess(item it, int diff);
PossibleDirection blockingDirection(PossibleDirection nonB, char type);

#endif //KOMMANDCALAND_ROOM_H
