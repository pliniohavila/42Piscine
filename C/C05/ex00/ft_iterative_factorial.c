#include "stdio.h"
#include "stdlib.h"

#define MAX 21474836

int ft_interative_factorial(int nb)
{
    int     r;

    r = nb;
    for (int i = (nb - 1); i > 0; i--)
    {
        if (r < MAX)
        {
            r *= i; 
        }
        else
        {
            return (-1);
        }
    }

    return r;
}

int     main(int argc, char *argv[])
{
    int     n;
    int     ft;

    if (argc != 2)
        n = 5;

    n = atoi(argv[1]);
    ft = ft_interative_factorial(n);

    printf("Fact: %d\n", ft); 
}