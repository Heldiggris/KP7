#include <stdio.h>
#include <stdlib.h>
#include "raz_matrix.h"
#include "complex.h"
#include <ctype.h>


Raz *raz_ind_create()
{
    Raz_ind *mt = (Raz_ind *)malloc(sizeof(Raz_ind));
    mt->next = NULL;
    return mt;
}

Raz *raz_create()
{
    Raz *mt = (Raz *)malloc(sizeof(Raz));
    mt->next = NULL;
    return mt;
}

void get_matrix(FILE *f, Raz *mat, Raz_ind *mat_ind, int n, int m)
{
    int index = 0;
    char a[40];
    Raz *new_elem;
    Raz_ind *new_elem_ind;
    Raz *mat_prev = mat;
    mat->next = NULL;
    for (int i = 0; i < n; ++i) {
        new_elem_ind = raz_ind_create();
        mat_ind->next = new_elem_ind;
        mat_ind->index = -1;
        for (int j = 0; j < m; ++j) {
            fscanf(f, "%40s", &a);
            if (a[0] != '0') {
                new_elem = raz_create();
                mat->next = new_elem;
                index += 1;
                mat->j = j;
                mat->value = complex_parse(a);
                mat->next_index = index;
                mat_prev = mat;
                mat = mat->next;
                mat->next_index = index;
                if (mat_ind->index == -1) {
                    mat_ind->index = index - 1;
                }
            }
        }
        mat_prev->next_index = 0;
        mat_ind = mat_ind->next;
    }
}

void print_matrochlen(Raz *mat, Raz_ind *mat_ind, double a, double b, int n)
{
    int ind_s = 0;
    int t_ind = 0;
    while (mat_ind->next) {
        if (mat_ind->index == -1) {
            for (int i = 0; i < ind_s; ++i) {
                printf("0\t");
            }
            printf("%.2lf\t", b);
            for (int i = ind_s; i < n - 1; ++i) {
                printf("0\t");
            }
            printf("\n");
        } else {
            int index = mat_ind->index;
            int t_j = 0;
            do {
                while(t_ind < index) {
                    mat = mat->next;
                    t_ind++;
                }
                for (;t_j < mat->j; ++t_j) {
                    if (t_j == ind_s) {
                        printf("%0.2lf\t", b);
                    } else {
                        printf("0\t");
                    }
                }
                if (t_j == ind_s) {
                    (mat->value.b * a < 0)? printf("%.2lf%.2lfi\t", mat->value.a * a + b, mat->value.b * a) : printf("%.2lf+%.2lfi\t", mat->value.a * a + b, mat->value.b * a);
                } else {
                    (mat->value.b * a < 0)? printf("%.2lf%.2lfi\t", mat->value.a * a, mat->value.b * a) : printf("%.2lf+%.2lfi\t", mat->value.a * a, mat->value.b * a);
                }
                t_j++;
                for (; t_j < n; ++t_j) {
                    if (t_j == ind_s) {
                        printf("%0.2lf\t", b);
                    } else {
                        printf("0\t");
                    }
                }
                index = mat->next_index;
            } while (mat->next_index != 0);
            printf("\n");
            t_j = 0;
        }
        mat_ind = mat_ind->next;
        ind_s += 1;
    }
}

void print_matrix(Raz *mat)
{
    while (mat->next) {
        (mat->value.b < 0)? printf("%d %.2lf%.2lfi %d\n", mat->j, mat->value.a, mat->value.b, mat->next_index) : printf("%d %.2lf+%.2lfi %d\n", mat->j, mat->value.a, mat->value.b, mat->next_index);
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

void rez_destroy(Raz *mat)
{
    if (mat->next != NULL) {
        rez_destroy(mat->next);
    }
    free(mat);
    mat = NULL;
}

void rez_ind_destroy(Raz_ind *mat)
{
    if (mat->next != NULL) {
        rez_ind_destroy(mat->next);
    }
    free(mat);
    mat = NULL;
}
