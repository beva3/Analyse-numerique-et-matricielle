#include "./matrice.0.1.h"

int main(){
    MATRIX m, m1;
    init_2d(&m, 4, 4);
    init_2d(&m1, 4,4);

    // if correct 
    get_matrix(&m,"data1.txt");
    get_matrix(&m1,"data2.txt");
    display(m);
    display(m1);
    // display(traspose(m));
    // display(sum(&m, &m));
    // display(prd(&m, &m));

    // display(triangle_sup(&m));
    // display(triangle_inf(&m));

    display(prd(&m,&m1));
    display(prd(&m1,&m));
    display(identity(4));

    // if not correct ...
    return 0;
}