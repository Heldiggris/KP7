#include <stdio.h>
#include <stdlib.h>
#include "raz_matrix.h"

void get_matrix(FILE *f, Raz *mat, Raz_ind *mat_ind)
{
    int n, m, index = 0;
    double a;
    Raz *new_elem;
    Raz_ind *new_elem_ind;
    Raz *mat_prev = mat;
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    mat->next = NULL;
    for (int i = 0; i < n; ++i) {
        new_elem_ind = (Raz_ind *)malloc(sizeof(Raz_ind));
        mat_ind->next = new_elem_ind;
        mat_ind->index = -1;
        for (int j = 0; j < m; ++j) {
            fscanf(f, "%lf", &a);
            if (a != 0) {
                new_elem = (Raz *)malloc(sizeof(Raz));
                mat->next = new_elem;
                index += 1;
                mat->j = j;
                mat->value = a;
                mat->next_index = index;
                mat_prev = mat;
                mat = mat->next;
                mat->next_index = index;
                if (mat_ind->index == -1) {
                    mat_ind->index = index;
                }
            }
        }
        mat_prev->next_index = 0;
        mat_ind = mat_ind->next;
    }
    mat->next = NULL;
}

void print_matrix(Raz *mat)
{
    while (mat->next) {
        printf("%d %lf %d\n", mat->j, mat->value, mat->next_index);
        mat = mat->next;
    }
}

void print_matrix_f(Raz_ind *mat)
{
    while (mat->next) {
        printf("%d ", mat->index);
        mat = mat->next;
    }
    printf("\n");

}