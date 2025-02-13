#ifndef __MATRICE__
#define __MATRICE__
#include <stdlib.h>
#include <stdio.h>

typedef struct Matrice{
    int row;
    int col;
    float **data;
} Matrice;

void initMatrice(float ***m, int row, int col);
Matrice* sum_(Matrice *m1, Matrice *m2);
Matrice* product_(Matrice *m1, Matrice *m2);
void getData_(char *filename, Matrice *m);
void displayMatrice(Matrice *m);

void getData(char *filename, float ***m, int row, int col);
// float **sum(float **m1, int r1, int l1, float **m2, int r2, int l2);
// float **product(float **m1, int r1, int l1, float **m2, int r2, int l2);
// void display(float **m, int row, int col);
// void initMatrice(float **m, int row, int col);

#endif