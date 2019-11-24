#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "chapter.h"
#include "movement.h"
#include "item.h"
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

    srand(time(NULL));
    int rows;
    int **roomLayout= getMovementTable(&rows);
    if (roomLayout == NULL)
    {
        printf("Table not imported\nThe game can't run\nExiting...\n");
        return 0;
    }
    item *inventory = NULL;
    item hand = {.next=NULL,.type="hand",.name="Default hand",.qual=100};
    addItem(&inventory,hand);
    listItems(inventory);


    chapter current = ReadChapt("rooms/1.txt");
    int x = 3,y = 1;


    while (true) {
        char command[10];
        char arg[10];

        DrawChapter(current);
        nl();
        ChooseNext(findPD(roomLayout,y,x));
        nl();
        scanf("%s",command);

        if (strcmp(command, "move") == 0) {
            scanf("%s", arg);
            PossibleDirection pd = findPD(roomLayout, y, x);

            int nextroom = moveTo(pd,&y,&x,arg[0]);

            if (nextroom != 0)
            {
                char path[50] = "rooms/";
                char num[3];
                sprintf(num, "%d.txt", nextroom);
                strcat(path, num);
                FreeChap(current);
                current = ReadChapt(path);
            }
        }
        else if (( strcmp(command, "pickup") == 0) || (strcmp(command, "get") == 0) )
        {
            if (strcmp(current.item.type, "NaI") == 0)
                printf("No items around\n");
            else
            {
                addItem(&inventory,current.item);
            }
        }

        else if (strcmp(command,"inv") == 0)
            listItems(inventory);

        else if ( strcmp(command,"exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        else
            printf("Come again pls...");



        nl();
    }

    FreeChap(current);
    freeItemsList(inventory);
    freeTable(roomLayout,rows);

    return 0;
}