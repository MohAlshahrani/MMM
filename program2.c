//
// Created by Mohammed Alshahrani on 10/6/22.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,k,M,N,K;
    int NB,MU,NU,KU;
    MU = NU = 2;
    KU = 2 ;
    N = M = K = NB = 1000;
    float A[N][K],B[K][M],C[N][M];
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
                                double temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;
                                for( int i1 = 0 ; i1 < 8 ; i1++ ){
                                    temp1 = A[i0*i1][k0*i1]*B[k0*i1][j0*i1];
                                    temp2 = A[i0*i1+1][k0*i1+1]*B[k0*i1+1][j0*i1+1];
                                    temp3 = A[i0*i1+2][k0*i1+2]*B[k0*i1+2][j0*i1+2];
                                    temp4 = A[i0*i1+3][k0*i1+3]*B[k0*i1+3][j0*i1+3];
                                    temp5 = A[i0*i1+4][k0*i1+4]*B[k0*i1+4][j0*i1+4];
                                    temp6 = A[i0*i1+5][k0*i1+5]*B[k0*i1+5][j0*i1+5];
                                    temp7 = A[i0*i1+6][k0*i1+6]*B[k0*i1+6][j0*i1+6];
                                    temp8 = A[i0*i1+7][k0*i1+7]*B[k0*i1+7][j0*i1+7];

                                    C[i0*i1][j0*i1] = C[i0*i1][j0*i1] + temp1;
                                    C[i0*i1+1][j0*i1+1] = C[i0*i1+1][j0*i1+1] + temp2;
                                    C[i0*i1+2][j0*i1+2] = C[i0*i1+2][j0*i1+2] + temp3;
                                    C[i0*i1+3][j0*i1+3] = C[i0*i1+3][j0*i1+3] + temp4;
                                    C[i0*i1+4][j0*i1+4] = C[i0*i1+4][j0*i1+4] + temp5;
                                    C[i0*i1+5][j0*i1+5] = C[i0*i1+5][j0*i1+5] + temp6;
                                    C[i0*i1+6][j0*i1+6] = C[i0*i1+6][j0*i1+6] + temp7;
                                    C[i0*i1+7][j0*i1+7] = C[i0*i1+7][j0*i1+7] + temp8;
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


}

