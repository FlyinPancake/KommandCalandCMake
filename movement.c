//
// Created by domoh on 14/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

#define LAYOUT_PATH "rooms/layout.txt"

int **getMovementTable() {

    int **eleje = (int**) malloc(sizeof(int*));
    int width = getWidth();
    if (width == -1)
        return NULL;
    FILE *fp = fopen(LAYOUT_PATH, "r");
    if (fp == NULL)
        return NULL;
    char *line = malloc((width*3+1) * sizeof(char));
    int rownum = 0;
    while (fgets(line, width * 3 - 1, fp) != NULL) {
        eleje = addNewLine(eleje,rownum);
        eleje[rownum] = (int*) malloc(sizeof(int)*width);

        for (int ii = 0; ii < width; ++ii) {

            sscanf(line, "%d ", (eleje[rownum] + ii));
            while (*line != ' ')
                line++;
            line++;

        }
        rownum++;
    }
    return eleje;
}

int getWidth() {
    FILE *f = fopen(LAYOUT_PATH, "r");
    if (f == NULL)
        return -1;
    char buf=fgetc(f);
    int count = 0;
    while (buf != '\n') {
        if (buf == ' ')
            count++;
        buf = fgetc(f);
    }
    fclose(f);
    return ++count;
}

void printLayout() {
    FILE *fp = fopen(LAYOUT_PATH, "r");
    if (fp == NULL) {
        printf("Reading the file was unsuccessful\nexiting\n");
        return;
    }
    char s[50];
    fgets(s, 50, fp);
    printf(s);
}

int **addNewLine(int **o,int rownum) {
    int **ret = (int**) malloc((rownum + 1)* sizeof(int*));
    for (int ii = 0; ii < rownum; ++ii) {
        ret[ii] = o[ii];
    }
    free(o);
    return ret;
}

PossibleDirection findPD(int **eleje, int x, int y) {
    PossibleDirection rtn = { .n = eleje[x - 1][y],
                              .e = eleje[x][y + 1],
                              .s = eleje[x + 1][y],
                              .w = eleje[x][y + 1]};
    return rtn;
}

void ChooseNext(PossibleDirection p) {
    printf("Available directions: ");
    if (p.n !=0) {
        printf("n ");
    }
    if (p.e !=0) {
        printf("e ");
    }
    if (p.s !=0) {
        printf("s ");
    }
    if (p.w !=0) {
        printf("w ");
    }
    printf("\n");
}