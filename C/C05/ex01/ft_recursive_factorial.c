#include "stdio.h"
#include "stdlib.h"

int     ft_recursive_fatorial(int nb)
{
    if (nb < 0)
        return (0);

    if (nb == 1)
        return (nb);

    return (nb * ft_recursive_fatorial((nb - 1)));
}

int     main(int argc, char *argv[])
{
    int     n;
    int     ft;

    if (argc != 2)
        return (-1);

    n = atoi(argv[1]);
    ft = ft_recursive_fatorial(n);

    printf("Fact of the %s is %d\n", argv[1], ft); 

    return (0);
}