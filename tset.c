#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int j_st;
    double value;
    int next_index;
}Raz;


// void fct(Raz *vv)
// {
//     vv->j_st = 120;
//     printf("%d\n", vv->j_st);
// }

int main(void)
{
    Raz *vv;
    vv->j_st = 56;
    // fct(vv);
    printf("%d\n", vv->j_st);
    return 0;
}