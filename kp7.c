#include <stdio.h>
#include <stdlib.h>
#include "raz_matrix.h"
#include "complex.h"

int main(int argc, char *argv[])
{
    int n;
    int m;
    double a;
    double b;
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    Raz mat;
    Raz_ind mat_ind;
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    get_matrix(in, &mat, &mat_ind, n, m);
    close(in);
    // print_matrix(&mat);
    // print_matrix_f(&mat_ind);
    // printf("\n");
    scanf("%lf", &a);
    scanf("%lf", &b);

    print_matrochlen(&mat, &mat_ind, a, b, n);

    return 0;
}