//
// Created by Mohammed Alshahrani on 10/3/22.
//
#include <stdio.h>
#include <stdlib.h>
//#include <papi.h>

int main() {
    float real_time, proc_time, mflops;
    long long flpops;
    int retval;

    int i,j,k,M,N,K;
    int NB,MU,NU,KU;
    MU = 1;
    NU = 1;
    KU = 4 ;
    int size = 20;
    N = size;
    M = size;
    K = size;
    NB = 20; // revise this
    int A[N][K],B[K][M],C[N][M];

    for (i = 0 ; i < K; i++) {
        for (j = 0; j < K; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }
/*
    if ( (retval = PAPI_flops_rate(PAPI_FP_OPS, &real_time, &proc_time, &flpops, &mflops)) < PAPI_OK )
    {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
    }
*/
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



                            printf("loop %d \n",k0);
                        }
                    }
                }
            }
        }
    }
/*
    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
    {
        printf("retval: %d\n", retval);
        exit(1);
    }
    printf("Real_time: %f Proc_time: %f flpops: %lld MFLOPS: %f\n",
           real_time, proc_time,flpops,mflops);
    exit(0);
*/
    return 0;
}

