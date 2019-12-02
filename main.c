#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "chapter.h"
#include "movement.h"
#include "item.h"
#include "game.h"

int main(void)
{

    srand(time(NULL));

    // Main menu
    bool gamerunning = true;
    while (gamerunning)
    {
        printf("Select menu item:\n");
        printf("\t1)New Game\n");
        printf("\t2)Load Saved Game\n");
        printf("\t3)Credits\n");
        printf("\t9)Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                play(0);
                break;
            case 2:
                printf("\nSelect savefile (1-3): ");
                int savefile;
                scanf("%d",&savefile);
                play(savefile);
                break;
            case 3:
                printf("Made by FlyinPancake in 2019\n#SayNoToSDL\n");
                break;
            case 9:
                gamerunning = false;
                break;
            default:
                printf("No option like that\n");
        }
    }

    return 0;
}