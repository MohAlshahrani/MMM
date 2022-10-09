#include <stdio.h>
#include <stdlib.h>
#include <papi.h>

int main() {
    int counter ( int event, float *rtime, float *ptime, long long *flpops, float *mflops );
    int i,j,k,m,K,n ;
    n = m = K = 10;
    float a[n][k],b[k][m],c[n][m];
    for (i = 0 ; i < K; i++) {
        for (j = 0; j < K; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }
    PAPI_flops_rate();
    for(i=0; i<n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < K; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    counter = PAPI_flops_rate();
    return 0;
}
