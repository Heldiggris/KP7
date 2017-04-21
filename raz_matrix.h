#ifndef _RAZ_MATRIX_H_
#define _RAZ_MATRIX_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Raz{
    int j;
    double value;
    int next_index;
    struct Raz *next;
}Raz;

typedef struct node_ind{
    int index;
    struct node_ind *next;
}Raz_ind;



void get_matrix(FILE *f, Raz *mat, Raz_ind *mat_ind);
void print_matrix(Raz *mat);
void print_matrix_f(Raz_ind *mat);


#endif