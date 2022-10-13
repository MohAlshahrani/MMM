//
// Created by Mohammed Alshahrani on 10/13/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float program_zero_a(int NB){

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
    printf(" %lf \n",  flops_s);
    return 0;
}

int main() {

    program_zero_a(8);
    program_zero_a(16);
    program_zero_a(32);
    program_zero_a(64);
    program_zero_a(128);
    program_zero_a(256);
    program_zero_a(512);
    program_zero_a(1024);
    return 0;

}