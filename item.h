//
// Created by flyinpancake on 24/11/2019.
//

#ifndef KOMMANDCALAND_ITEM_H
#define KOMMANDCALAND_ITEM_H

#include <stdbool.h>
#include "chapter.h"


item *findbyType(item *invenory, char type[]);
void addItem(item **clist, item toAdd);
void freeItemsList(item *clist);
void listItems (item *listOi);
void reverseInv(item **clist);
bool useItem(action act, item *itm);





#endif //KOMMANDCALAND_ITEM_H
