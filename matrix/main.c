#include "./matrice.0.1.h"

int main(){
    MATRIX m = {NULL,0, 0};
    init_2d(&m, 4, 4);

    // if correct 
    get_matrix(&m,"data1.txt");
    display(m);
    // display(traspose(m));
    // display(sum(&m, &m));
    // display(prd(&m, &m));

    display(triangle_sup(&m));
    display(triangle_inf(&m));



    // if not correct ...
    return 0;
}