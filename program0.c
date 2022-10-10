#include <stdio.h>
#include <stdlib.h>
#include <papi.h>

int main() {
    float real_time, proc_time, mflops;
    long long flpops;
    int retval;

    int i,j,k,m,K,n ;
    n = m = K = 1000;
    int16_t a[n][K],b[K][m],c[n][m] ;
    for (i = 0 ; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand();
            b[i][j] = rand();
        }
    }

    if ( (retval = PAPI_flops_rate(PAPI_FP_OPS, &real_time, &proc_time, &flpops, &mflops)) < PAPI_OK )
    {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
    }

    for(i=0; i<n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < K; k++) {
                c[i][j] += a[i][k] * b[k][j];
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
