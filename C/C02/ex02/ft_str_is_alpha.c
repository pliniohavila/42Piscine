#include "stdio.h"

int     ft_str_is_alpha(char *str)
{
    if ((*str >= 65) && (*str <= 90))
        return (1);

    return (0);
}

int     main(void)
{
    char a;
    char b;

    a = 'A';
    b = 'b';
    printf("A: %d ", a);
    printf("B: %d ", b);
    printf("\n");
    printf("TEST:\nA: %d (is should 1)\nb: %d (is should 0)\n", ft_str_is_alpha(&a), ft_str_is_alpha(&b));
}