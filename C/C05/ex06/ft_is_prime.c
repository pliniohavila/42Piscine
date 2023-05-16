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


int     main(int argc, char *argv[])
{
    int     number;
    int     ft;

    if (argc != 2)
        return (-1);

    number = atoi(argv[1]);
    ft = ft_is_prime(number);

    printf("Check (%d) is prime: %d\n", number, ft); 

    return (0);
}