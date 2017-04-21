#include <stdio.h>
#include <stdlib.h>
#include "raz_matrix.h"




int main(int argc, char *argv[])
{
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
    get_matrix(in, &mat, &mat_ind);

    print_matrix(&mat);
    print_matrix_f(&mat_ind);

    return 0;
}