#ifndef __MATRICE__
#define __MATRICE__
#include <stdlib.h>
#include <stdio.h>


typedef struct MATRIX{
    float **matrix;
    int row;
    int col;
} MATRIX;

// control
void init_2d(MATRIX *m, int row, int col);
void get_matrix(MATRIX *m, char *fname);
void display(MATRIX m);

// operation
MATRIX traspose(MATRIX m);
MATRIX sum(MATRIX *m1, MATRIX *m2);
MATRIX prd(MATRIX *m1, MATRIX *m2);
MATRIX triangle_sup(MATRIX *m);
MATRIX triangle_inf(MATRIX *m);
MATRIX identity(int order);

#endif