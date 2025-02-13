#include "matrice.h"

void display(float **m, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            printf("%g%c", m[i][j], (j == col - 1) ? '\n' : ' ');
}