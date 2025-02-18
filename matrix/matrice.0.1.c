#include "./matrice.0.1.h"
void init_2d(MATRIX *m, int row, int col){
    printf("Init matrix\n");
    (*m).row = row;
    (*m).col = col;
    (*m).matrix = (float **)malloc((*m).row * sizeof(float *));
    if ((*m).matrix == NULL)
    {
        printf("Error allocating memory\n");
        //
        return;
    }
    for (int i = 0; i < (*m).row; i++)
    {
        (*m).matrix[i] = (float *)malloc((*m).col * sizeof(float));
        if ((*m).matrix[i] == NULL)
        {
            printf("Error allocating memory\n");
            //
            return;
        }
    }

    // default value = 0
    for (int i = 0; i < (*m).row; i++)
        for (int j = 0; j < (*m).col; j++)
            (*m).matrix[i][j] = 0;
}

void get_matrix(MATRIX *m, char *fname){
    printf("Get matrix in %s\n", fname);
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    init_2d(m, m->row, m->col);
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->col; j++)
            fscanf(f, "%f,", &m->matrix[i][j]);

    printf("read successfull\n");

    fclose(f);
}

void display(MATRIX m){
    printf("display matrix : size = [%03d] x [%03d]\n", m.row, m.col);

    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            printf("%3g%c", m.matrix[i][j], (j == m.col - 1) ? '\n' : ' ');
}

MATRIX traspose(MATRIX m){
    // trp
    MATRIX trp = {NULL, 0, 0};
    init_2d(&trp, m.row, m.col);

    printf("Transpose ...\n");
    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            trp.matrix[i][j] = m.matrix[j][i];

    // return trp
    return trp;
}

MATRIX sum(MATRIX *m1, MATRIX *m2){
    if (m1->row != m2->row || m1->col != m2->col)
        return (MATRIX){NULL}; // matrices must have the same dimensions   
    
    MATRIX s = {NULL, 0, 0};
    init_2d(&s, m1->row, m1->col);
    for (int  i = 0; i < s.row; i++)
        for (int j = 0; j < s.col; j++)
            s.matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        
    return s;
}

// product
MATRIX prd(MATRIX *m1, MATRIX *m2){
    if (m1->row != m2->row || m1->col != m2->col)
        return (MATRIX){NULL}; // matrices must have the same dimensions   
    
    MATRIX prd = {NULL, 0, 0};
    init_2d(&prd, m1->row, m1->col);

    for (int i = 0; i < prd.row; i++)
        for (int j = 0; j < prd.col; j++){
            prd.matrix[i][j] = 0; // init sum by 0
            for (int k = 0; k < m1->col; k++)
               prd.matrix[i][j] += m1->matrix[i][k] * m2->matrix[k][j];
        }    

    return prd;
}

MATRIX triangle_sup(MATRIX *m){
    MATRIX result = {NULL, 0, 0};
    init_2d(&result, m->row, m->col);

    for (int i = 0; i < m->row ; i++)
        for (int j = 0; j < m->col; j++){
            if(i > j){
                result.matrix[i][j] = 0;
            }else{
                result.matrix[i][j] = m->matrix[i][j];
            }
        }
    return result;
}

MATRIX triangle_inf(MATRIX *m){
    MATRIX result = {NULL, 0, 0};
    init_2d(&result, m->row, m->col);

    for (int i = 0; i < m->row ; i++)
        for (int j = 0; j < m->col; j++){
            if(i < j){
                result.matrix[i][j] = 0;
            }else{
                result.matrix[i][j] = m->matrix[i][j];
            }
        }
    return result;
}

MATRIX identity(int order){
    MATRIX result = {NULL, 0, 0};
    init_2d(&result, order, order);

    for (int i = 0; i < result.row; i++)
        for (int j = 0; j < result.col; j++)
            if(i == j)
                result.matrix[i][j] = 1;

    return result;
}