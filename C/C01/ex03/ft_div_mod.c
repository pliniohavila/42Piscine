#include "stdio.h"

void    ft_div_mod(int a, int b, int *div, int *mod)
{
    *mod = a % b;
    *div = ((a - *mod) / b);
}

int     main(void)
{
    int     a;
    int     b;
    int     div;
    int     mod;

    a = 17;
    b = 3;
    ft_div_mod(a, b, &div, &mod);
    printf("A: %d - B: %d\n", a, b);
    printf("DIV: %d - MOD: %d\n", div, mod);
    return (0);
}