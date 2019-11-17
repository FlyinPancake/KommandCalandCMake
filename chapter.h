//
// Created by domoh on 14/11/2019.
//

#ifndef KOMMANDCALAND_CHAPTER_H
#define KOMMANDCALAND_CHAPTER_H
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

char *GetData(FILE *f);
chapter ReadChapt(FILE *f);
void FreeChap(chapter c);
#endif //KOMMANDCALAND_CHAPTER_H
