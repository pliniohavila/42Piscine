#include "stdio.h"

int     ft_str_is_printable(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        if (!((str[i] >= 32) && (str[i] < 127)))
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
    b = "Str\tinG";
    printf("string: %d (should be 1) \n", ft_str_is_printable(a));
    printf("Str\tinG: %d (should be 0) \n", ft_str_is_printable(b));
}