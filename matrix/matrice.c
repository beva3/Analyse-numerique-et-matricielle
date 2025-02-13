#include "matrice.h"

void getData(char *filename, float ***m, int row, int col){
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        printf("Error opening file\n");
        return;
    }

    // *m = (float **)malloc(row * sizeof(float *));
    // for (int i = 0; i < row; i++)
    //     (*m)[i] = (float *)malloc(col * sizeof(float));
    initMatrice(m, row, col);

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

float **product(float **m1, int r1, int l1, float **m2, int r2, int l2){
    if (l1 != r2)
        return NULL;
    
    float **result = NULL;

    // float **result = (float **)malloc(r1 * sizeof(float *));
    // for (int i = 0; i < r1; i++)
    //     result[i] = (float *)malloc(l2 * sizeof(float));
    initMatrice(&result, r1, l2);

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < l2; j++){
            result[i][j] = 0;   // init sum = 0
            for (int k = 0; k < l1; k++)
                result[i][j] += m1[i][k] * m2[k][j];
        }

    return result;
}

void initMatrice(float ***m, int row, int col){
    *m = (float **)malloc(row * sizeof(float *));
    if (*m == NULL){
        printf("Error allocating memory\n");
        return;
    }

    for (int i = 0; i < row; i++){
        (*m)[i] = (float *)malloc(col * sizeof(float));
        if ((*m)[i] == NULL){
            printf("Error allocating memory\n");
            return;
        }
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            (*m)[i][j] = 0;

    printf("Memory allocated successfully : matrix %d x %d\n", row, col);
}