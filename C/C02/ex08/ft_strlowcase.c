#include "stdio.h"

char    *ft_strupcase(char *str)
{
    char    *src_start;

    src_start = str;
    while(*str != '\0')
    {
        if ((*str >= 'A') && (*str <= 'Z'))
        {
            *str = (*str) + ('a' - 'A');
        }
        str++;
    }
    return (src_start);
}

int     main(void)
{
    char    src[7] = "STRING";
    char    *struped;

    printf("Before: %s\n", src);
    struped = ft_strupcase(src);
    printf("After: %s\n", struped);
    printf("After: %s (original) \n", src);


    return (0);
}