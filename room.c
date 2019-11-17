//
// Created by flyinpancake on 17/11/2019.
//

#include "room.h"
#include <stdio.h>
#include <stdlib.h>
#include "chapter.h"
#include <stdbool.h>

bool actionSuccess(item it, int diff) {
    if (diff == 0)
        return true;
    return  (it.qual > rand() % diff);
}

PossibleDirection blockingDirection(PossibleDirection nonB, char type) {
    switch (type) {
        case 'n':
            nonB.n = 0;
            break;
        case 'e':
            nonB.e = 0;
            break;
        case 's':
            nonB.s = 0;
            break;
        case 'w':
            nonB.w = 0;
            break;

    }
}


