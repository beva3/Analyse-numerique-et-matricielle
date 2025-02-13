#include "./matrice.h"

int main()
{

    float **matrix = NULL;
    getData("matrix.txt", &matrix, 2, 3);
    // 

    // float **m = (float **)malloc(2 * sizeof(float *));
    // for (int i = 0; i < 2; i++)
    //     m[i] = (float *)malloc(3 * sizeof(float));
    
    // for (int i = 0; i < 2; i++)
    //     for (int j = 0; j < 3; j++)
    //         m[i][j] = 0;


    // display(m, 2, 3);

    return 0;
}