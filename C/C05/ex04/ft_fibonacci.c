#include "stdio.h"
#include "stdlib.h"

int     ft_fibonacci(int index)
{
    if (index <= 2)
        return (1);

    return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int     main(int argc, char *argv[])
{
    int     index;
    int     ft;

    if (argc != 2)
        return (-1);

    index = atoi(argv[1]);
    ft = ft_fibonacci(index);

    printf("FIB: Index(%d) is %d\n", index, ft); 

    return (0);
}
