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
            printf("%2g%c", m[i][j], (j == col - 1) ? '\n' : ' ');
}

float **sum(float **m1, int r1, int l1, float **m2, int r2, int l2){
    if (r1 != r2 || l1 != l2)
        return NULL;

    float **result = (float **)malloc(r1 * sizeof(float *));
    for (int i = 0; i < r1; i++)
        result[i] = (float *)malloc(l1 * sizeof(float));

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < l1; j++)
            result[i][j] = m1[i][j] + m2[i][j];

    return result;

}