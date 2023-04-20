#include "stdio.h"

void    ft_ultimate_div_mod(int *a, int *b)
{
    int     div;
    int     mod;

    mod = *a % *b;
    div = ((*a - mod) / *b);
    *a = div; 
    *b = mod;
}

int     main(void)
{
    int     a;
    int     b;

    a = 17;
    b = 5;
    printf("BEFORE\n A: %d - B: %d\n", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("AFTER\n A: %d - B: %d\n", a, b);
}