#include "./matrice.h"

int main()
{

    float **matrix = NULL;
    float **matrix2 = NULL;
    getData("data1.txt", &matrix, 3, 3);
    getData("data2.txt", &matrix2, 3, 3);

    display(sum(matrix,3,3,matrix2, 3,3), 3, 3);
    display(product(matrix,3,3,matrix2, 3,3), 3, 3);

    // float **matrix = NULL;
    // initMatrice(&matrix, 3, 3);
    // display(matrix, 3, 3);

    // clean memory

    return 0;
}