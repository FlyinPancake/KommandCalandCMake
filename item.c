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
        if (strcmp(currentListItem -> type, toAdd.type) == 0) {
            if (currentListItem -> qual < toAdd.qual) {
                printf("You dropped %s, and kept %s\n", currentListItem->name, toAdd.name);
                currentListItem ->qual = toAdd.qual;
                strcpy(currentListItem -> type, toAdd.type);
                strcpy(currentListItem -> name, toAdd.name);
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

bool useItem(action act, item *itm) {
    if(itm == NULL)
    {
        printf("You don't have that item\n");
        return false;
    }
    if (strcmp(itm -> type,act.type) != 0)
    {
        printf("You'll need something else...\n");
        return false;
    }
    if (itm -> qual < act.diff)
    {
        printf("Find some better equipment!\n");
        return false;
    }
    else
    {
        printf("Success!\n");
        return true;
    }

}

item *findbyType(item *invenory, char *type) {
    while (invenory != NULL)
    {
        if (strcmp(invenory -> type, type) == 0)
            break;
        invenory = invenory -> next;
    }
    return invenory;
}
