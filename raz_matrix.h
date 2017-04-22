#ifndef _RAZ_MATRIX_H_
#define _RAZ_MATRIX_H_
#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

typedef struct Raz{
    int j;
    complex_t value;
    int next_index;
    struct Raz *next;
}Raz;

typedef struct node_ind{
    int index;
    struct node_ind *next;
}Raz_ind;

void print_matrochlen(Raz *mat, Raz_ind *mat_ind, double a, double b, int n);
void get_matrix(FILE *f, Raz *mat, Raz_ind *mat_ind, int n, int m);
void print_matrix(Raz *mat);
void print_matrix_f(Raz_ind *mat);
void print_complex(complex_t mat);

#endif