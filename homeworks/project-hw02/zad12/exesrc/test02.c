//ispitivanje funkcionalnosti cmplx_mul funkcije

#include <stdio.h>
#include <cmplx.h>


int main(void) {
    cmplx_t c;
    cmplx_t lista[3];
    lista[0][0] = 1.;
    lista[0][1] = 1.;
    lista[1][0] = 3.;
    lista[1][1] = -2.;
    lista[2][0] = -1.;
    lista[2][1] = -1.;

    printf("Ispitivanje funkcionalnosti cmplx_mul funkcije...\n");
    
    for(int i = 0; i < 3; i++) {
        printf("a: %lf + %lfj, b: %lf + %lfj\n", lista[i][0], lista[i][1], lista[(i+1)%3][0], lista[(i+1)%3][1]);
        cmplx_mul(lista[i], lista[(i+1)%3], c);
        printf("Rezultat a * b: %lf + %lfj\n", c[0], c[1]);
        printf("\n");
    }

    printf("------------\n");
    
    return 0;
}