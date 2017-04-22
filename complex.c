#include <stdio.h>
#include "complex.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

complex_t complex_parse(char *a)
{
    complex_t x;
    x.a = 0;
    x.b = 0;
    int i = 0;
    double st = 1;
    int sign_a = 1;
    int sign_b = 1;
    int rev = 0;
    while ((a[i] != '\0' && a[i] != '+' && a[i] != '-') || i == 0) {
        if (isdigit(a[i])) {
            if(st != 1) {
                x.a += st * (double)(a[i] -'0');
                st *= 0.1;
            } else {
                x.a = x.a * 10 + (double)(a[i] -'0');
            }
        } else if(a[i] == '.') {
            st = 0.1;
        } else if (a[i] == '-') {
            sign_a *= -1;
        } else if (a[i] == 'i') {
            rev = 1;
        }
        i++;
    }
    st = 1;
    while (a[i] != '\0') {
        if (isdigit(a[i])) {
            if(st != 1) {
                x.b += st * (double)(a[i] -'0');
                st *= 0.1;
            } else {
                x.b = x.b * 10 + (double)(a[i] -'0');
            }
        } else if(a[i] == '.') {
            st = 0.1;
        } else if (a[i] == '-') {
            sign_b *= -1;
        }
        i++;
    }
    x.a *= sign_a;
    x.b *= sign_b;
    if(rev == 1) {
        x.b = x.a;
        x.a = 0;
    }
    return x;
}

complex_t complex_sum(complex_t x, complex_t y) // сложение
{
    complex_t t;
    t.a = x.a + y.a;
    t.b = x.b + y.b;
    return t;
}

complex_t complex_sub(complex_t x, complex_t y) // вычитание.
{
    complex_t t;
    t.a = x.a - y.a;
    t.b = x.b - y.b;
    return t;
}
 
complex_t complex_mul(complex_t x, complex_t y) // умножение
{
    complex_t t;
    t.a = x.a * y.a - x.b * y.b;
    t.b = x.a * y.b + x.b * y.a;
    return t;
}

complex_t complex_div(complex_t x, complex_t y) // деление
{
    complex_t t;
    t.a = (x.a * y.a + x.b * y.b)/(y.a*y.a+y.b*y.b);
    t.b = (x.a * y.b - x.b * y.a)/(y.a*y.a+y.b*y.b);
    return t;
}