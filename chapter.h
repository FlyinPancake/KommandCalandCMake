//
// Created by domoh on 14/11/2019.
//

#ifndef KOMMANDCALAND_CHAPTER_H
#define KOMMANDCALAND_CHAPTER_H

#include <stdio.h>

typedef struct action
{
    int diff;
    char *type;
    char blocking;
} action;

typedef struct item
{
    char *name, *type;
    int qual;
} item;

typedef struct chapter
{
    char *story;
    action action;
    item item;
} chapter ;

void DrawChapter(const chapter chp);
chapter ReadChapt(const char *room );
void FreeChap(chapter c);
#endif //KOMMANDCALAND_CHAPTER_H
