#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "chapter.h"
#include "movement.h"

#define RED  "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void WrChap(chapter c) {
    printf("Story: %s\n", c.story);
}

int main(void)
{

    /*FILE *story = fopen("storyif (fp == NULL)
        return NULL;.txt", "r");
    if (story == NULL)
    {din2D
        printf("Room not found" );
    }
    else {
        chapter one = ReadChapt(story);
        WrChap(one);
        FreeChap(one);
    }*/
    srand(time(NULL));
    int **roomLayout= getMovementTable();
    if (roomLayout != NULL)
        printf("Table imported\n");
    ChooseNext(findPD(roomLayout,2,3));


    return 0;
}