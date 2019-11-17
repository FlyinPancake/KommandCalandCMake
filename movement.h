//
// Created by domoh on 14/11/2019.
//

#ifndef KOMMANDCALAND_MOVEMENT_H
#define KOMMANDCALAND_MOVEMENT_H

typedef struct PossibleDirection {
    int n,e,s,w;
} PossibleDirection;

int getWidth();
int **getMovementTable();
void printLayout();
int **addNewLine(int **o,int newLines);
PossibleDirection findPD(int **eleje, int x, int y);
void ChooseNext(PossibleDirection p);

#endif //KOMMANDCALAND_MOVEMENT_H
