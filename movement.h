//
// Created by domoh on 14/11/2019.
//

#ifndef KOMMANDCALAND_MOVEMENT_H
#define KOMMANDCALAND_MOVEMENT_H

typedef struct PossibleDirection {
    int n,e,s,w;
} PossibleDirection;

int getWidth();
int **getMovementTable(int *rows);
void printLayout();
int **addNewLine(int **o,int newLines);
PossibleDirection findPD(int **eleje, int y, int x);
void ChooseNext(PossibleDirection p);
int moveTo(PossibleDirection pd , int *y , int *x, char dir);
PossibleDirection blockingDirection(PossibleDirection nonB, char type);
void freeTable(int **table, int rows);



#endif //KOMMANDCALAND_MOVEMENT_H
