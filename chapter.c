//
// Created by domoh on 14/11/2019.
//

#include <stdio.h>
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
        char *tmp = (char*) malloc(sizeof(char) * (ii+1));
        for (int jj = 0; jj < ii; jj++)
        {
            tmp[jj] = rtn.type[jj];
        }
        free(rtn.type);
        rtn.type = tmp;
        rtn.type[++ii] = *raw;
    } while (*raw++ != '[');

    char *tmp = (char*) malloc(sizeof(char) * (ii+1));
    for (int jj = 0; jj < ii; jj++)
    {
        tmp[jj] = rtn.type[jj];
    }
    free(rtn.type);
    rtn.type = tmp;
    rtn.type[++ii] = '\0';

    raw++;

    //---------------------------------DIFF-------------------------------
    ii = 0;
    char *diffTxt = NULL;
    do
    {
        char *tmp = (char*) malloc(sizeof(char) * (ii+1));
        for (int jj = 0; jj < ii; ++jj) {
            tmp[jj] = diffTxt[jj];
        }
        free(diffTxt);

        tmp[++ii] = *raw;
        diffTxt = tmp;

    } while (*raw++ != ',');

    tmp = (char*) malloc(sizeof(char) * (ii+1));
    for (int jj = 0; jj < ii; ++jj) {
        tmp[jj] = diffTxt[jj];
    }

    free(diffTxt);
    tmp[++ii] = '\0';
    diffTxt = tmp;

    sscanf(diffTxt, "%d " ,rtn.diff);
    
    raw++;

    //-------------------------DIRECTION------------------------------
    free(eleje);
    return rtn;
}

chapter ReadChapt(FILE *f)
{
    chapter c;

    c.story = GetData(f);
    GetData(f);
    GetData(f);

    return c;
}

void FreeChap(chapter c) {
    free(c.story);
}