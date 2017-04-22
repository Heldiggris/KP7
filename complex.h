#ifndef _COMPLEX_H_
#define _COMPLEX_H_

typedef struct
    {
     double a,b;
    } complex_t;

#include <stdio.h>
#include "complex.h"

complex_t complex_parse(char *a);

complex_t complex_sum(complex_t x, complex_t y);

complex_t complex_sub(complex_t x, complex_t y);

complex_t complex_mul(complex_t x, complex_t y);

complex_t complex_div(complex_t x, complex_t y);

#endif