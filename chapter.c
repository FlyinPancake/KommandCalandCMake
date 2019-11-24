//
// Created by domoh on 14/11/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chapter.h"

char *GetData(FILE *f)
{
    char buf;
    do
    {
        buf = fgetc(f);
    } while (buf != '/');

    char *data;
    int ii = 0;
    data = (char*) malloc(sizeof(char));
    do
    {
        buf = fgetc(f);
        char *tmp = (char*) malloc(sizeof(char) * (ii+1));
        for (int jj = 0; jj < ii; jj++)
        {
            tmp[jj] = data[jj];
        }
        free(data);
        data = tmp;

        data[ii++] = buf;
        // printf("%c", buf);
    } while (buf != '/');
    data[--ii] = '\0';

    return data;
}

action GetAction(FILE *f)
{
    char *raw = GetData(f);
    char *eleje = raw;
    action rtn;
    // --------------------------TYPE-----------------------------
    int ii= 0;
    rtn.type = NULL;
    do
    {
        ii++;
    } while (*raw++ != '[');
    *--raw = '\0';
    rtn.type = (char*) malloc(sizeof(char) * (ii+1));
    raw = raw - ii + 1;

    strcpy(rtn.type,raw);

    raw = raw + ii;

    //---------------------------------DIFF-------------------------------
    ii = 0;
    do
    {
        ii++;
    } while (*raw++ != ']');
    *--raw = '\0';

    raw -= ii - 1;

    sscanf(raw,"%d",&rtn.diff);

    raw += ii ;

    //-------------------------DIRECTION------------------------------

    rtn.blocking = *raw;

    free(eleje);
    return rtn;
}

item GetItem(FILE *f)
{
    item rtn = {.type ="NaI"};

    char *start = GetData(f);
    char *raw = start;
    if (strlen(raw) == 0)
        return  rtn;

    char *type = raw;
    while (*++raw != '[');
    *raw = '\0';
    strcpy(rtn.type, type);

    char *qual = raw + 1;
    while (*++raw != ',');
    *raw = '\0';
    sscanf(qual, "%d", &rtn.qual);

    char *name = raw + 1;
    while (*++raw != ']');
    *raw = '\0';
    strcpy(rtn.name, name);

    rtn.next = NULL;

    free(start);

    return rtn;
}
chapter ReadChapt(const char *room)
{
    FILE *f = fopen(room,"r");
    chapter c;

    c.story = GetData(f);
    c.action = GetAction(f);
    c.item = GetItem(f);
    fclose(f);
    return c;

}

void FreeChap(chapter c) {
    free(c.story);
    free(c.action.type);

}

void DrawChapter(const chapter chp) {
    printf("%s\n", chp.story);
}

