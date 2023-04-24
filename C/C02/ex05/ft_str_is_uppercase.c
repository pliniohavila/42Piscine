#include "stdio.h"

int     ft_str_is_uppercase(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        if (!((str[i] >= 65) && (str[i] <= 90)))
        {
            return (0);
        }
        i++;
    }

    return (1);
}

int     main(void)
{
    char    *a;
    char    *b;

    a = "string";
    b = "StrinG";
    printf("string: %d (should be 0) \n", ft_str_is_uppercase(a));
    printf("StrinG: %d (should be 1) \n", ft_str_is_uppercase(b));
}