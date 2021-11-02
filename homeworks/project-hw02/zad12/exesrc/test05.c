//ispitivanje funkcionalnosti cmplx_real funkcije

#include <stdio.h>
#include <cmplx.h>
#include <math.h>

int main(void) {
    double c;
    double lista[2][2];
    lista[0][0] = sqrt(2);
    lista[0][1] = M_PI/4.;
    lista[1][0] = sqrt(2);
    lista[1][1] = 5.*M_PI/4.;

    printf("Ispitivanje funkcionalnosti cmplx_real funkcije...\n");
    
    for(int i = 0; i < 2; i++) {
        printf("abs: %lf, fi: %lf\n", lista[i][0], lista[i][1]);
        c = cmplx_real(lista[i][0], lista[i][1]);
        printf("Rezultat Re: %lf\n", c);
        printf("\n");
    }

    printf("------------\n");
    
    return 0;
}