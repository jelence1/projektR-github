#include <math.h>
#include <cmplx.h>

// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = (a[0]*b[0] - a[1]*b[1]) / (pow(b[0],2) + pow(b[1], 2));
    c[1] = (a[0]*b[1] + a[1]*b[0]) / (pow(b[0],2) + pow(b[1], 2));

}

// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = a[0]*b[0] - a[1]*b[1];
    c[1] = a[0]*b[1] + a[1]*b[0];

}

// returns |a|
double cmplx_mag(cmplx_t a) {
    double a_cmplx[2];
    a_cmplx[0] = sqrt(pow(a[0], 2) + pow(a[1], 2)); //abs
    a_cmplx[1] = atan(a[1] / a[0]); //phi

    return a_cmplx[0];
}

// returns phase in radians of a 
double cmplx_phs(cmplx_t a) {
    double a_cmplx[2];
    a_cmplx[0] = sqrt(pow(a[0], 2) + pow(a[1], 2)); //abs
    a_cmplx[1] = atan(a[1] / a[0]); //phi

    if (a_cmplx[0] < 0 && a_cmplx[1] >= 0) {
        a_cmplx[1] = M_PI - a_cmplx[1];
    }
    else if (a_cmplx[0] < 0 && a_cmplx[1] < 0) {
        a_cmplx[1] += M_PI;
    }

    return a_cmplx[1];
}

// returns real part of mag/_phs
double cmplx_real(double mag, double phs) {
    return mag * cos(phs);
}

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs) {
    return mag * sin(phs);
}

// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {
    cmplx_t tmp, rez;
    double phi;
    for(int i = 0; i < N; i++) {
        output[i][0] = 0;
        output[i][1] = 0;

        for(int j = 0; j < N; j++) {
            phi = -2* M_PI * (1./N) * i * j;
            tmp[0] = cmplx_real(1,phi);
            tmp[1] = cmplx_imag(1,phi);
            cmplx_mul(input[j], tmp, rez);

            output[i][0] += rez[0];
            output[i][1] += rez[1];
        }
    }
    
}

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {
    cmplx_t tmp, rez;
    double phi;
    for (int i = 0; i < N; i++) {
        output[i][0] = 0;
        output[i][1] = 0;

        for (int j = 0; j < N; j++) {
            phi = 2 * M_PI * (1./N) * i * j;
            tmp[0] = cmplx_real(1, phi);
            tmp[1] = cmplx_imag(1, phi);
            cmplx_mul(input[j], tmp, rez);

            output[i][0] += rez[0];
            output[i][1] += rez[1];
        }

        output[i][0] *= (1./N);
        output[i][1] *= (1./N);
    }
}
