#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float program_zero(int NB){

    uint64_t flops = 0 ;

    int i,j,k,m,K,n ;
    n = m = K = NB;
    float a[n][K],b[K][m],c[n][m];
    for (i = 0 ; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }
    time_t begin = clock();
    for(i=0; i<n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < K; k++) {
                c[i][j] += a[i][k] * b[k][j];
                flops += 2;
            }
        }
    }

    time_t end = clock();

    double flops_s = flops/(end - begin);
    printf("NB = %d \t FLOPS/s = %d \n", NB, flops_s);
    return 0;
}

int main() {

    program_zero(16);
    program_zero(20);
    program_zero(24);
    program_zero(28);
    program_zero(32);
    program_zero(36);
    program_zero(40);
    program_zero(44);
    program_zero(48);
    program_zero(52);
    program_zero(56);
    program_zero(60);
    program_zero(64);
    program_zero(68);
    program_zero(72);
    program_zero(76);
    program_zero(80);

    return 0;

}