//
// Created by flyinpancake on 17/11/2019.
//

#include "debug.h"
#include <stdio.h>
#include "chapter.h"

void PrintAction(action ac) {
    printf("%s\n", ac.type);
    printf("%d\n", ac.diff);
    printf("%c\n", ac.blocking);
}