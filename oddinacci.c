#include <stdlib.h>
#include "oddinacci.h"

long oddinacci(long n) {
    if (n == 0 || n == 1) {
        return n;
    } else if (n % 2 == 0) {
        return oddinacci(n - 1) + oddinacci(n - 2);
    } else {
        return oddinacci(n - 1) + oddinacci(n - 2) + oddinacci(n - 3);
    }
}

long oddinacci_fast(long n) {
    if (n == 0 || n == 1) {
        return n;
    }
    long*val=malloc(sizeof(long)*(n+1));
    val[0]=0;
    val[1]=1;
    for (long i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            val[i] = val[i - 1] + val[i - 2];
        } else {
            val[i] = val[i - 1] + val[i - 2] + val[i - 3];
        }
    }
    long result = val[n];
    free(val);
    return result;
}
