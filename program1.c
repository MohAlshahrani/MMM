//
// Created by Mohammed Alshahrani on 10/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <papi.h>

int main() {
    float real_time, proc_time, mflops;
    long long flpops;
    int retval;

    int i,j,k,M,N,K;
    int NB,MU,NU,KU;
    MU = NU = 2;
    KU = 1 ;
    N = M = K = NB = 50;
    double A[N][K],B[K][M],C[N][M];
    for (i = 0 ; i < K; i++) {
        for (j = 0; j < K; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }
// part (b) asks for micro blocking
// read micro blocking and loop unrolling
// adjust the rest of the code to go with required result.
// MMM loop nest (j, i, k)
    if ( (retval = PAPI_flops_rate(PAPI_FP_OPS, &real_time, &proc_time, &flpops, &mflops)) < PAPI_OK )
    {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
    }

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

                            for(int k00=k0; k00<=(k0 + KU); k00++){
                                    // k0 equals to NB
                                //for( int j00=j0; j00<=(j0 + NU); j00++){

                                    //for(int i00=i0; i00<=(i0 + MU); i00++){

                                        // unroll loops, must MU * NU additions and multiplications
                                        double temp1,temp2,temp3,temp4;
                                        for( int i1 = 0 ; i1 < 4 ; i1++ ){
                                            temp1 = A[i0*i1][k00]*B[k00][j0*i1];
                                            C[i0*i1][j0*i1] = C[i0*i1][j0*i1] + temp1;
                                            temp2 = A[i0*i1+1][k00]*B[k00][j0*i1];
                                            C[i0*i1+1][j0*i1+1] = C[i0*i1+1][j0*i1+1] + temp2;
                                            temp3 = A[i0*i1+2][k00]*B[k00][j0*i1];
                                            C[i0*i1+2][j0*i1+2] = C[i0*i1+2][j0*i1+2] + temp3;
                                            temp4 = A[i0*i1+3][k00]*B[k00][j0*i1];
                                            C[i0*i1+3][j0*i1+3] = C[i0*i1+3][j0*i1+3] + temp4;
                                        }


                                        //C[i00][j00]=C[i00][j00]+A[i00][k00] * B[k00][j00];



                                    //}
                                //}
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

