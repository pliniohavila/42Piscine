#include "stdio.h"
#include "stdlib.h"

int     ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);

    return nb * ft_recursive_power(nb, (power - 1));
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
    ft = ft_recursive_power(base, exp);

    printf("%d ** %d is %d\n", base, exp, ft); 

    return (0);
}
