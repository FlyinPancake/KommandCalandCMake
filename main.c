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
void nl() {
    printf("\n");
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


    chapter current = ReadChapt("rooms/1.txt");
    int x = 3,y = 1;


    while (true) {
        char command[10];
        char arg[10];

        DrawChapter(current);
        nl();
        ChooseNext(findPD(roomLayout,y,x));
        nl();
        scanf("%s %s",command,arg);

        if (strcmp(command, "move") == 0) {
            PossibleDirection pd = findPD(roomLayout, y, x);
            int nextroom;
            int x_p = x, y_p = y;
            switch (arg[0]) {
                case 'n':
                    nextroom = pd.n;
                    y--;
                    break;
                case 'e':
                    nextroom = pd.e;
                    x++;
                    break;
                case 'w':
                    nextroom = pd.w;
                    x--;
                    break;
                case 's':
                    nextroom = pd.s;
                    y++;
                    break;
                default:
                    nextroom = 0;
                    break;
            }

            if (nextroom == 0)  {
                printf("You can't go there!\n");
                x = x_p;
                y = y_p;
                goto reDraw;
            }
            char path[50] = "rooms/";
            char num[3];
            sprintf(num, "%d.txt", nextroom);
            strcat(path, num);
            current = ReadChapt(path);
            goto reDraw;
        }

        else if (strcmp(command,"exit") == 0)
            break;

        else {
            printf("Come again pls...");
            nl();
        }

        reDraw:
        nl();
    }


    return 0;
}