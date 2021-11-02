/* Napisati program test_dft.c koji mora generirati realni 
signal sin(2 * pi * 50 * t) uz frekvenciju otipkavanja 
fs = 200 Hz i zatim napraviti dft transformaciju te 
rezultat slijedno zapisati u datoteku koristeći 
funkciju write_word. */


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <io.h>
#include <cmplx.h>


//sin func for generating the signal
double f_t(double t) {
    return sin(2 * M_PI * 50 * t);
}


int main(void) {
    int fs = 200, N = 20; //fs and N - No. of samples
    double T = 1./fs, t = 0;
    cmplx_t signal[N];
    cmplx_t signal_dft[N];
    cmplx_t signal_idft[N];
    int fd, word;
    
    //sampling
    for(int i = 0; i < N; i++) {
        signal[i][0] = f_t(t);
        signal[i][1] = 0.;
        t += T;        
    }

    cmplx_dft(signal, signal_dft, N); //signal_dft[i][0] Re, signal_dft[i][1] Im
    
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {

            float vrijednost = signal_dft[i][j];
            void *a = (void *) &vrijednost;
            int vrijednost_ieee = *((int *) a);
            int vrijednost_cijeli_broj = (int) vrijednost;

            fd = open("new.bin", O_WRONLY | O_CREAT | O_APPEND, 00700); //00700 - r,w,exe usr

            write_word(fd, vrijednost_ieee);
        }
    }

    printf("Signal sin(2 * PI * 50 * t): \n");
    printf("DFT: \n");

    for (int k = 0; k < N; k++) {
        printf("%f %f\n", signal_dft[k][0], signal_dft[k][1]);
    }

    printf("------------\n");
    
    return 0;
}