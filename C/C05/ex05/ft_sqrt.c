#include "stdio.h"
#include "stdlib.h"

int     ft_sqrt(int nb)
{
    int     i;
    int     count;

    i = 1;
    count = 0;
    // use pell equation
    while (nb > 0)
    {
        nb -= i;
        count++;
        i += 2;
    }    

    if (nb == 0)
    {
        return count;
    }

    return (0);
}

int     main(int argc, char *argv[])
{
    int     number;
    int     ft;

    if (argc != 2)
        return (-1);

    number = atoi(argv[1]);
    ft = ft_sqrt(number);

    printf("SQRT(%d) is %d\n", number, ft); 

    return (0);
}
