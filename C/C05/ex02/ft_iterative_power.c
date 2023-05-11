#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

int     ft_iterative_power(int nb, int power)
{
    int     r;

    r = nb;
    if ((nb == 0 && power != 0) || power < 0)
        return (0);
    if ((power == 0) || ((nb < 0) && (power == 0)))
        return (1);

    for (int i = 1; (i < power) && (r > INT_MIN && r < INT_MAX); i++)
        r = r * nb;

    return r; 
}

int     main(int argc, char *argv[])
{
    int     base;
    int     exp;
    int     ft;

    if (argc != 3)
        return (-1);

    base = atoi(argv[1]);
    exp = atoi(argv[2]);
    ft = ft_iterative_power(base, exp);

    printf("%d ** %d is %d\n", base, exp, ft); 

    return (0);
}
