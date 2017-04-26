#include <stdio.h>
#include <stdlib.h>
#include "raz_matrix.h"
#include "complex.h"

int main(int argc, char *argv[])
{
    int n = 0;
    int m = 0;
    double a = 0.0;
    double b = 0.0;
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    Raz *mat = raz_create();
    Raz_ind *mat_ind = raz_ind_create();
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    get_matrix(in, mat, mat_ind, n, m);
    fclose(in);
    scanf("%lf", &a);
    scanf("%lf", &b);

    print_matrochlen(mat, mat_ind, a, b, n);
    rez_destroy(mat);
    rez_ind_destroy(mat_ind);
    return 0;
}