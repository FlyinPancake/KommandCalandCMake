#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "chapter.h"
#include "movement.h"
#include "debug.h"

#define RED  "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


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
    chapter current = ReadChapt("rooms/1.txt");
    while (true) {
        char command[10];
        char arg[10];

        DrawChapter(current);
        scanf("%s %s");

        

    }


    return 0;
}