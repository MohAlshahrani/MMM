//
// Created by Mohammed Alshahrani on 10/6/22.
//
#include <stdio.h>
#include <stdlib.h>
//#include <papi.h>

int main() {
    //float real_time, proc_time, mflops;
    //long long flpops;
    //int retval;

    int i,j,k,M,N,K;
    int NB,MU,NU,KU;
    MU = NU = 2;
    KU = 2 ;
    N = M = K = NB = 10;
    double A[N][K],B[K][M],C[N][M];
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
// MMM loop nest (j, i, k)
    for(i=0; i<N; i+=NB){

        for(j=0; j<M; j+=NB){

            for(k=0; k<K; k+=NB){

// mini-MMM loop nest (i0, j0, k0)

                for(int i0=i; i0<(i + NB); i0+=MU){

                    for(int j0=j; j0<(j + NB); j0+=NU){

                        for(int k0=k; k0<(k + NB); k0+=KU){

// micro-MMM loop nest (j00, i00)
//Block into micro MMMs with MU= NU= 2, KU= 1.
//The inner triple loop should have the kij order. You can use the code given in Section 5.2
// for your implementation. Unroll (manually) the innermost i and j-loop such that
// multiplications and additions alternate. Perform scalar replacement (manually).

                            //for(int k00=k0; k00<=(k0 + KU); k00++){
                            // k0 equals to NB
                            //for( int j00=j0; j00<=(j0 + NU); j00++){
                            //for(int i00=i0; i00<=(i0 + MU); i00++){
                            float temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8
                                    , temp9,temp10,temp11,temp12,temp13,temp14,temp15,temp16;
                            for( int i1 = 0 ; i1 < 8 ; i1++ ){
                                temp1 = A[i0*i1][k0*i1]*B[k0*i1][j0*i1];
                                temp2 = A[i0*i1+1][k0*i1+1]*B[k0*i1+1][j0*i1+1];
                                temp3 = A[i0*i1+2][k0*i1+2]*B[k0*i1+2][j0*i1+2];
                                temp4 = A[i0*i1+3][k0*i1+3]*B[k0*i1+3][j0*i1+3];
                                temp5 = A[i0*i1+4][k0*i1+4]*B[k0*i1+4][j0*i1+4];
                                temp6 = A[i0*i1+5][k0*i1+5]*B[k0*i1+5][j0*i1+5];
                                temp7 = A[i0*i1+6][k0*i1+6]*B[k0*i1+6][j0*i1+6];
                                temp8 = A[i0*i1+7][k0*i1+7]*B[k0*i1+7][j0*i1+7];
                                temp9 = A[i0*i1+8][k0*i1+8]*B[k0*i1+8][j0*i1+8];
                                temp10 = A[i0*i1+9][k0*i1+9]*B[k0*i1+9][j0*i1+9];
                                temp11 = A[i0*i1+10][k0*i1+10]*B[k0*i1+10][j0*i1+10];
                                temp12 = A[i0*i1+11][k0*i1+11]*B[k0*i1+11][j0*i1+11];
                                temp13 = A[i0*i1+12][k0*i1+12]*B[k0*i1+12][j0*i1+12];
                                temp14 = A[i0*i1+13][k0*i1+13]*B[k0*i1+13][j0*i1+13];
                                temp15 = A[i0*i1+14][k0*i1+14]*B[k0*i1+14][j0*i1+14];
                                temp16 = A[i0*i1+15][k0*i1+15]*B[k0*i1+15][j0*i1+15];

                                C[i0*i1][j0*i1] = C[i0*i1][j0*i1] + temp1;
                                C[i0*i1+1][j0*i1+1] = C[i0*i1+1][j0*i1+1] + temp2;
                                C[i0*i1+2][j0*i1+2] = C[i0*i1+2][j0*i1+2] + temp3;
                                C[i0*i1+3][j0*i1+3] = C[i0*i1+3][j0*i1+3] + temp4;
                                C[i0*i1+4][j0*i1+4] = C[i0*i1+4][j0*i1+4] + temp5;
                                C[i0*i1+5][j0*i1+5] = C[i0*i1+5][j0*i1+5] + temp6;
                                C[i0*i1+6][j0*i1+6] = C[i0*i1+6][j0*i1+6] + temp7;
                                C[i0*i1+7][j0*i1+7] = C[i0*i1+7][j0*i1+7] + temp8;
                                C[i0*i1+8][j0*i1+8] = C[i0*i1+8][j0*i1+8] + temp9;
                                C[i0*i1+9][j0*i1+9] = C[i0*i1+9][j0*i1+9] + temp10;
                                C[i0*i1+10][j0*i1+10] = C[i0*i1+10][j0*i1+10] + temp11;
                                C[i0*i1+11][j0*i1+11] = C[i0*i1+11][j0*i1+11] + temp12;
                                C[i0*i1+12][j0*i1+12] = C[i0*i1+12][j0*i1+12] + temp13;
                                C[i0*i1+13][j0*i1+13] = C[i0*i1+13][j0*i1+13] + temp14;
                                C[i0*i1+14][j0*i1+14] = C[i0*i1+14][j0*i1+14] + temp15;
                                C[i0*i1+15][j0*i1+15] = C[i0*i1+15][j0*i1+15] + temp16;
                            }


                            //C[i00][j00]=C[i00][j00]+A[i00][k00] * B[k00][j00];



                            //}
                            //}
                        //}
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

