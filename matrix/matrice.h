#ifndef __MATRICE__
#define __MATRICE__
#include <stdlib.h>
#include <stdio.h>
void initMatrice(float ***m, int row, int col);
float **sum(float **m1, int r1, int l1, float **m2, int r2, int l2);
void getData(char *filename, float ***m, int row, int col);
void display(float **m, int row, int col);
// void initMatrice(float **m, int row, int col);

#endif