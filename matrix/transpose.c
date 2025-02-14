#include <stdio.h>
#include <stdlib.h>

typedef struct MATRIX
{
    float **matrix;
    int row;
    int col;
} MATRIX;

void init_2d(MATRIX *m, int r, int c)
{
    printf("Init matrix\n");
    (*m).row = r;
    (*m).col = c;
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

void get_matrix(MATRIX *m, char *fname)
{
    printf("Get matrix in %s\n", fname);
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("Error opening file");
        return;
    }
    init_2d(m, m->row, m->col);
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->col; j++)
            fscanf(f, "%f,", &m->matrix[i][j]);

    printf("read successfull\n");

    fclose(f);
}

MATRIX traspose(MATRIX m)
{
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

void display(MATRIX m)
{
    printf("display matrix : size = [%03d] x [%03d]\n", m.row, m.col);

    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            printf("%3g%c", m.matrix[i][j], (j == m.col - 1) ? '\n' : ' ');
}

int main()
{
    MATRIX m = {NULL, 0, 0};
    printf("Transpose matrix\n");

    // alloc matrix
    init_2d(&m, 3, 3);

    // get data
    get_matrix(&m, "data1.txt");
    display(m);

    // transeose
    traspose(m);

    // display
    display(traspose(m));

    return 0;
}