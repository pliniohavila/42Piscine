#include "unistd.h"

void     ft_print_combn(int n)
{
    char    buffer[4];

    buffer[3] = ',';
    buffer[4] = 32;
    for (int i = 0; i <= n; i++) 
    {
        for (int j = (i + 1); j <= n; j++)
        {
            buffer[0] = (i + 48);
            buffer[1] = (j + 48);
            write(1, &buffer, 4);
        }
    }
}

int     main(void)
{
    ft_print_combn(9);
    return (0);
}