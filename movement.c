//
// Created by domoh on 14/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

#define LAYOUT_PATH "rooms/layout.txt"

int **getMovementTable(int *rows) {

    int **eleje = (int**) malloc(sizeof(int*));
    int width = getWidth();
    if (width == -1)
        return NULL;
    FILE *fp = fopen(LAYOUT_PATH, "r");
    if (fp == NULL)
        return NULL;
    char *lineS = malloc(((width*3)+1) * sizeof(char));
    char *line = lineS;
    int rownum = 0;
    while (fgets(line, width * 3 - 2, fp) != NULL) {
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
    free(lineS);
    
    *rows = rownum;
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

void freeTable(int **table, int rows) {
    for (int ii = 0; ii < rows; ++ii) {
        free(table[ii]);
    }
    free(table);
}

PossibleDirection findPD(int **eleje, int y, int x) {
    PossibleDirection rtn = { .n = eleje[y - 1][x],
                              .e = eleje[y][x + 1],
                              .s = eleje[y + 1][x],
                              .w = eleje[y][x + 1]};
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


int moveTo(PossibleDirection pd, int *y, int *x, char dir) {
    int nextroom = 0;
    int x_p = *x, y_p = *y;
    switch (dir) {
        case 'n':
            nextroom = pd.n;
            *y -= 1;
            break;
        case 'e':
            nextroom = pd.e;
            *x += 1;
            break;
        case 'w':
            nextroom = pd.w;
            *x -= 1;
            break;
        case 's':
            nextroom = pd.s;
            *y += 1;
            break;
    }

    if (nextroom == 0) {
        printf("You can't go there!\n");
        *x = x_p;
        *y = y_p;
    }
    return nextroom;
}


PossibleDirection blockingDirection(PossibleDirection nonB, char type) {
    switch (type) {
        case 'n':
            nonB.n = 0;
            break;
        case 'e':
            nonB.e = 0;
            break;
        case 's':
            nonB.s = 0;
            break;
        case 'w':
            nonB.w = 0;
            break;

    }
}



