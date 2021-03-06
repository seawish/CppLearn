//
// Created by zsb on 17/8/3.
//

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifdef  HAVE_POW
#include <math.h>
#else

#include <math_functions.h>

#endif


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

#ifdef HAVE_POW
    printf("Now we use standard libraray. \n");
    double result = pow(base, exponent);
#else
    printf("Now we use our own Math libraray. \n");
    double result = power(base, exponent);
#endif

    printf("%g ^ %d is %g\n", base, exponent, result);

    return 0;
}