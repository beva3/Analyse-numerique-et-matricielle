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


void getData_(char *filename, Matrice *m){
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        printf("Error opening file\n");
        return;
    }

    initMatrice(&m->data, m->row, m->col);

    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->col; j++)
            fscanf(f, "%f,", &m->data[i][j]);
    
    printf("read successfull\n");

    fclose(f);
}

// void display(float **m, int row, int col){
//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             printf("%2g%c", m[i][j], (j == col - 1) ? '\n' : ' ');
// }

void displayMatrice(Matrice *m){
    printf("size = %d X %d\n", m->row, m->col);
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->col; j++)
            printf("%2g%c", m->data[i][j], (j == m->col - 1) ? '\n' : ' ');
}

/**
 * float **sum(float **m1, int r1, int l1, float **m2, int r2, int l2){
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
*/

Matrice *sum_(Matrice *m1, Matrice *m2){
    if (m1->row != m2->row || m1->col != m2->col)
        return NULL; // matrices must have the same dimensions

    // Allocate memory for the result matrix
    Matrice *result = (Matrice *)malloc(sizeof(Matrice));
    result->row = m1->row;
    result->col = m1->col;

    // Allocate memory for data
    initMatrice(&result->data, result->row, result->col);

    // Perform element-wise addition
    for (int i = 0; i < result->row; i++){
        for (int j = 0; j < result->col; j++){
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return result;
}

/*
float **product(float **m1, int r1, int l1, float **m2, int r2, int l2){
    if (l1 != r2)
        return NULL;

    float **result = NULL;

    // float **result = (float **)malloc(r1 * sizeof(float *));
    // for (int i = 0; i < r1; i++)
    //     result[i] = (float *)malloc(l2 * sizeof(float));
    initMatrice(&result, r1, l2);

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < l2; j++)
        {
            result[i][j] = 0; // init sum = 0
            for (int k = 0; k < l1; k++)
                result[i][j] += m1[i][k] * m2[k][j];
        }

    return result;
}
*/

Matrice *product_(Matrice *m1, Matrice *m2)
{
    if (m1->col != m2->row)
        return NULL;

    Matrice *result = (Matrice *)malloc(sizeof(Matrice));
    result->row = m1->row;
    result->col = m2->col;
    initMatrice(&result->data, result->row, result->col);

    for (int i = 0; i < result->row; i++)
        for (int j = 0; j < result->col; j++)
        {
            result->data[i][j] = 0;
            for (int k = 0; k < m1->col; k++)
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
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

Matrice transpose(Matrice m){
    Matrice t;
    t.row = m.col; 
    t.col = m.row;

    printf("Transpose matrix\n");

    return t;
}