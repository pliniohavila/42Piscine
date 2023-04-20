#include "stdio.h"

void    ft_swap(int *a, int *b)
{
    int     tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     main(void) 
{
    int     a;
    int     b;

    a = 42;
    b = 24;
    printf("A: %d - B: %d \n", a, b);
    ft_swap(&a, &b);
    printf("A: %d - B: %d \n", a, b);
}

