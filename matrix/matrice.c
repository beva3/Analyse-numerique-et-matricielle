#include "matrice.h"

void getData(char *filename, float ***m, int row, int col){
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        printf("Error opening file\n");
        return;
    }

    *m = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
        (*m)[i] = (float *)malloc(col * sizeof(float));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            fscanf(f, "%f,", &(*m)[i][j]);
    fclose(f);
}

void display(float **m, int row, int col){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            printf("%g%c", m[i][j], (j == col - 1) ? '\n' : ' ');
}