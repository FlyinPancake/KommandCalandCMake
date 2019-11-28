//
// Created by flyinpancake on 24/11/2019.
//

#ifndef KOMMANDCALAND_ITEM_H
#define KOMMANDCALAND_ITEM_H

#include <stdbool.h>
#include "chapter.h"

bool actionSuccess(item it, int diff);
void addItem(item **clist, item toAdd);
void freeItemsList(item *clist);
void listItems (item *listOi);
void reverseInv(item **clist);




#endif //KOMMANDCALAND_ITEM_H
