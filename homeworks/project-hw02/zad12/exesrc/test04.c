//ispitivanje funkcionalnosti cmplx_phs funkcije

#include <stdio.h>
#include <cmplx.h>


int main(void) {
    double c;
    cmplx_t lista[3];
    lista[0][0] = 1.;
    lista[0][1] = 1.;
    lista[1][0] = 3.;
    lista[1][1] = -2.;
    lista[2][0] = -1.;
    lista[2][1] = -1.;

    printf("Ispitivanje funkcionalnosti cmplx_phs funkcije...\n");
    
    for(int i = 0; i < 3; i++) {
        printf("a: %lf + %lfj\n", lista[i][0], lista[i][1]);
        c = cmplx_phs(lista[i]);
        printf("Rezultat fi(rad): %lf\n", c);
        printf("\n");
    }

    printf("------------\n");
    
    return 0;
}