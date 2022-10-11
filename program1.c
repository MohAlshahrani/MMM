//
// Created by Mohammed Alshahrani on 10/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <papi.h>
#include <libc.h>

float program_one(int NB){
    float real_time, proc_time, mflops;
    long long flpops;
    int retval;

    int i,j,k,M,N,K;
    int MU,NU,KU;
    MU = 1;
    NU = 1;
    KU = 1 ;
    int size = NB;
    N = size;
    M = size;
    K = size;
    // revise this
    int A[N][K],B[K][M],C[N][M];

    for (i = 0 ; i < K; i++) {
        for (j = 0; j < K; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }

    if ( (retval = PAPI_flops_rate(PAPI_FP_OPS, &real_time, &proc_time, &flpops, &mflops)) < PAPI_OK )
    {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
    }

    for (i = 0 ; i < N ; i += NB) {
        for (j = 0 ; j < M ; j += NB) {
            for (k = 0 ; k < K ; k += NB) {

// mini-MMM loop nest (i0, j0, k0)

                for (int i0 = i; i0 < (i + NB); i0 += MU) {
                    for (int j0 = j; j0 < (j + NB); j0 += NU) {
                        for (int k0 = k; k0 < (k + NB); k0 += KU) {


                            // micro-MMM loop nest (j00, i00)
                            double temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
                            for(int k00=k0; k00<=(k0 + KU); k00++){
                                int j00 = NU * k00;
                                temp1 = A[MU*j00][k00]*B[k00][j00] ;
                                C[(MU*j00)][j00] += temp1 ;
                                temp2 = A[MU*j00+1][k00]*B[k00][j00];
                                C[MU*j00+1][j00] += temp2 ;
                                temp3 = A[MU*j00+2][k00]*B[k00][j00];
                                C[MU*j00+2][j00] += temp3;
                                temp4 = A[MU*j00][k00]*B[k00][j00+1];
                                C[MU*j00][j00+1] += temp4;
                                temp5 = A[MU*j00+1][k00]*B[k00][j00+1];
                                C[MU*j00+1][j00+1] += temp5;
                                temp6 = A[MU*j00+2][k00]*B[k00][j00+1];
                                C[MU*j00+2][j00+1] += temp6;
                                temp7 = A[MU*j00][k00]*B[k00][j00+2];
                                C[MU*j00][j00+2] += temp7 ;
                                temp8 = A[MU*j00+1][k00]*B[k00][j00+2];
                                C[MU*j00+1][j00+2] += temp8;
                                temp9 = A[MU*j00+2][k00]*B[k00][j00+2];
                                C[MU*j00+2][j00+2] += temp9;
                                //printf("loop %d \n",k00);
                            }
                        }
                    }
                }
            }
        }
    }

    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
    {
        printf("retval: %d\n", retval);
        exit(1);
    }
    printf("Real_time: %f Proc_time: %f flpops: %lld MFLOPS: %f\n",
           real_time, proc_time,flpops,mflops);
    exit(0);

    return 0;
}

int main() {

    program_one(16);
    sleep(100);
    program_one(20);
    program_one(24);
    program_one(28);
    program_one(32);
    program_one(36);
    program_one(40);
    program_one(44);
    program_one(48);

    program_one(52);
    program_one(56);
    program_one(60);
    program_one(64);
    program_one(68);
    program_one(72);
    program_one(76);
    program_one(80);
    printf("mo3");


}

