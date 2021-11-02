/* Napisati program test_idft.c koji mora učitati sadržaj
prethodno generirane datoteke koristeći funkciju read_word
napraviti inverznu dft transoformaciju i usporediti signal 
s generiranim signalom. */


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <cmplx.h>



int main(void) {
    int fd, N = 20; //N - No. of samples
    cmplx_t signal[N], signal_idft[N];

    fd = open("new.bin", O_RDONLY | O_CREAT | O_APPEND, 00700); //00700 - r,w,exe usr

    int i = 0, j = 0;
    for(int k = 0; k < N*2; k++) {

        int vrijednost_ieee = read_word(fd);
        void *a = (void *) &vrijednost_ieee;
        float vrijednost = *((float *) a);

        signal[i][j] = vrijednost;

        j++;
        if (j == 2) {
            i++;
            j = 0;
        }
    }
    
    cmplx_idft(signal, signal_idft, N);
    
    printf("\n Nakon IDFT: \n");
    for (int k = 0; k < N; k++) {
        printf("%f %f\n", signal_idft[k][0], signal_idft[k][1]);
    }

    
    printf("------------\n");
    
    return 0;
}