#include "./matrice.h"

int main(){

    float **matrix = NULL;
    float **matrix2 = NULL;
    getData("data1.txt", &matrix, 3, 3);
    getData("data2.txt", &matrix2, 3, 3);

    Matrice a = {3, 3, matrix};
    Matrice b = {3, 3, matrix2};

    Matrice *m2 = sum_(&a, &b);
    Matrice *m3 = product_(&a, &b);

    // displayMatrice(m2);
    // displayMatrice(m3);


    // Matrice *matrix = (Matrice *)malloc(sizeof(Matrice));
    // Matrice *matrix2 = (Matrice *)malloc(sizeof(Matrice));
    // getData_("data1.txt", matrix);
    // getData_("data2.txt", matrix2);
    // displayMatrice(matrix);

    Matrice t = transpose(*m2);
    // clean memory

    return 0;
}