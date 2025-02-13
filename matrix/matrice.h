#ifndef __MATRICE__
#define __MATRICE__
#include <stdlib.h>
#include <stdio.h>

float **sum(float **m1, float **m2);
void getData(char *filename, float ***m, int row, int col);
void display(float **m, int row, int col);
// void initMatrice(float **m, int row, int col);

#endif