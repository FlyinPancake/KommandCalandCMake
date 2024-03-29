//
// Created by flyinpancake on 26/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "chapter.h"
#include "movement.h"



void saveGame(int savNo, int x, int y, item *inv) {
    char path[8] = "saves/";
    char no[2];
    sprintf(no,"%d", savNo);
    strcat(path,no);
    FILE *f = fopen(path,"w");
    fprintf(f, "%d %d\n",x, y);
    while (inv != NULL)
    {
        fprintf(f, "%s %d %s\n",inv -> type, inv -> qual, inv ->name);
        inv = inv -> next;
    }
    fclose(f);
}


void nl() {
    printf("\n");
}


Save loadSave(int savNo) {
    char path[8] = "saves/";
    char no[2];
    sprintf(no, "%d", savNo);
    strcat(path, no);
    FILE *f = fopen(path, "r");

    Save errorSave = {.y = 0, .x = 0, .inv = NULL};
    if(f == NULL)
    {
        perror("Savefile not found\n");
        return errorSave;
    }

    Save toLoad;

    fscanf(f, "%d %d", &toLoad.x, &toLoad.y);

    char line[47];
    toLoad.inv = NULL;
    while (fgets(line, 46, f) != NULL)
    {
        item *toAdd = (item*) malloc(sizeof(item));
        sscanf(line, "%s %d %[^\n]",toAdd -> type,&(toAdd -> qual),toAdd -> name);
        if (toAdd -> qual != 0)
            addItem(&toLoad.inv, *toAdd);
    }

    reverseInv(&toLoad.inv);

    return toLoad;
}

void play(int savNo)
{
    Save saved = loadSave(savNo);

    int y = saved.y;
    int x = saved.x;
    item *inventory = saved.inv;

    int rows;
    int **roomLayout= getMovementTable(&rows);
    if (roomLayout == NULL)
    {
        printf("Table could not be imported. The game can't run\nConsider reinstalling the game\n");
        return;
    }


    char path[50] = "rooms/";
    char num[3];
    sprintf(num, "%d.txt", roomLayout[y][x]);
    strcat(path, num);

    chapter current = ReadChapt(path);
    DrawChapter(current);

    while (true) {
        char command[10];
        char arg[10];

        PossibleDirection pd = blockingDirection(findPD(roomLayout,y,x),current.action.blocking);
        ChooseNext(pd);
        nl();
        scanf("%s",command);

        if (strcmp(command, "move") == 0) {
            scanf("%s", arg);

            int nextroom = moveTo(pd,&y,&x,arg[0]);

            if (nextroom != 0)
            {
                char path[50] = "rooms/";
                char num[3];
                sprintf(num, "%d.txt", nextroom);
                strcat(path, num);
                FreeChap(current);
                current = ReadChapt(path);
                nl();
                nl();
                DrawChapter(current);
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

        else if ( strcmp(command,"save") == 0)
        {
            while (!(savNo > 0 && savNo < 4))
            {
                printf("Select save slot (1-3): ");
                scanf("%d", &savNo);
            }
            saveGame(savNo, x,y,inventory);
            printf("Game Saved!");
        }

        else if (strcmp(command, "use")==0)
        {
            scanf("%s", arg);
            if (useItem(current.action,findbyType(inventory,arg)))
            {
                current.action.blocking=' ';
            }
        }
        else if (strcmp(command,"room") == 0)
        {
            DrawChapter(current);
        }
        else if (strcmp(command, "halp") == 0)
        {
            halp();
        }

        else
            printf("Come again pls...\nUse halp to get halp");
        nl();
    }

    FreeChap(current);
    freeItemsList(inventory);
    freeTable(roomLayout,rows);
}


void halp() {
    FILE *f = fopen("halp.txt", "r");
    char c = fgetc(f);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(f);
    }
    nl();
    fclose(f);
}
