#include "stdio.h"
#include "stdlib.h"

int     ft_is_prime(int nb)
{
    int     i;

    i = 2;
    while ((i != nb) && (nb % i != 0))
    {
        i++;
    }

    if (i == nb)
        return (1);

    return (0);
}

int     ft_find_next_prime(int nb)
{
    int     next_prime;

    next_prime = nb;
    while (1)
    {
        if (ft_is_prime(next_prime) == 1)
            return next_prime;

        next_prime++;
    }
}


int     main(int argc, char *argv[])
{
    int     number;
    int     ft;

    if (argc != 2)
        return (-1);

    number = atoi(argv[1]);
    ft = ft_find_next_prime(number);

    printf("Find next prime from (%d): %d\n", number, ft); 

    return (0);
}

