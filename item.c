//
// Created by flyinpancake on 24/11/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

bool actionSuccess(item it, int diff) {
    if (diff == 0)
        return true;
    return  (it.qual > rand() % diff);
}

void listItems(item *listOi) {
    printf("Name\t\tType\tQuality\n");
    while (listOi != NULL)
    {
        printf("%s\t%s\t%d\n", listOi -> name, listOi -> type, listOi -> qual);
        listOi = listOi -> next;
    }
}


void addItem(item **clist, item toAdd) {
    item *currentListItem = *clist;
    while (currentListItem != NULL)
    {
        if (currentListItem -> type == toAdd.type) {
            if (currentListItem -> qual < toAdd.qual) {
                printf("You dropped %s, and kept %s\n", currentListItem->name, toAdd.name);
                return;
            } else {
                printf("%s is not wort your time. %s is better", toAdd.name, currentListItem->name);
                return;
            }
        }
        currentListItem = currentListItem -> next;
    }
    item *newEntry = (item*) malloc(sizeof(item));
    item *nowSec = *clist;
    *clist = newEntry;
    newEntry -> qual = toAdd.qual;
    strcpy(newEntry -> name, toAdd.name);
    strcpy(newEntry -> type, toAdd.type);
    newEntry -> next = nowSec;
}

void freeItemsList(item *clist) {
    while (clist != NULL)
    {
        item prev = *clist;
        free(clist);
        clist = prev.next;
    }
}

void reverseInv(item **clist)
{
    item *mozg = *clist;
    if (mozg == NULL)
        return;
    item *elozo = NULL;
    while (mozg != NULL)
    {
        item *kov = mozg -> next;
        mozg -> next = elozo;
        elozo = mozg;
        mozg = kov;

    }
    *clist = elozo;
}
