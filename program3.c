//
// Created by Mohammed Alshahrani on 10/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float program_three(int NB){
    int i,j,k,M,N,K;
    int MU,NU,KU;
    MU = 1;
    NU = 1;
    KU = 4 ;
    int size = NB;
    N = size;
    M = size;
    K = size;
    uint64_t flops = 0 ;

    int A[N][K],B[K][M],C[N][M];

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


                            double temp1,temp2,temp3,temp4;
                            temp1 = A[i0][k0]*B[k0][j0];
                            C[i0][j0] += temp1;

                            temp2 = A[i0][k0+1]*B[k0+1][j0];
                            C[i0][j0] += temp2;

                            temp3 = A[i0][k0+2]*B[k0+2][j0];
                            C[i0][j0] += temp3;

                            temp4 = A[i0][k0+3]*B[k0+3][j0];
                            C[i0][j0] += temp4;

                            flops += 8;
                        }
                    }
                }
            }
        }
    }
    time_t end = clock();

    double flops_s = flops/(end - begin);
    printf("NB = %d \t FLOPS/s = %d \n", NB, flops_s);

    return 0;
}

int main() {

    program_three(16);
    program_three(20);
    program_three(24);
    program_three(28);
    program_three(32);
    program_three(36);
    program_three(40);
    program_three(44);
    program_three(48);
    program_three(52);
    program_three(56);
    program_three(60);
    program_three(64);
    program_three(68);
    program_three(72);
    program_three(76);
    program_three(80);


}

