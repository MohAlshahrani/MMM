//
// Created by Mohammed Alshahrani on 10/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float program_two(int NB){
    int i,j,k,M,N,K;
    int MU,NU,KU;
    MU = 1;
    NU = 1;
    KU = 2 ;
    int size = NB;
    N = size;
    M = size;
    K = size;
    uint64_t flops = 0 ;
    float A[N][K],B[K][M],C[N][M];

    for (i = 0 ; i < K; i++) {
        for (j = 0; j < K; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }

    time_t begin = clock();

    for (i = 0 ; i < N ; i += NB) {
        for (j = 0 ; j < M ; j += NB) {
            for (k = 0 ; k < K ; k += NB) {

// mini-MMM loop nest (i0, j0, k0)

                for (int i0 = i; i0 < (i + NB); i0 += MU) {
                    for (int j0 = j; j0 < (j + NB); j0 += NU) {
                        for (int k0 = k; k0 < (k + NB); k0 += KU) {


                            float temp1,temp2;
                            temp1 = A[i0][k0]*B[k0][j0];
                            C[i0][j0] += temp1;

                            temp2 = A[i0][k0+1]*B[k0+1][j0];
                            C[i0][j0] += temp2;

                            flops += 4;


                        }
                    }
                }
            }
        }
    }

    time_t end = clock();

    double flops_s = flops/(end - begin);
    printf(" %lf \n",  flops_s);

    return 0;
}


int main() {

    program_two(16);
    program_two(20);
    program_two(24);
    program_two(28);
    program_two(32);
    program_two(36);
    program_two(40);
    program_two(44);
    program_two(48);
    program_two(52);
    program_two(56);
    program_two(60);
    program_two(64);
    program_two(68);
    program_two(72);
    program_two(76);
    program_two(80);

    return 0;
}

