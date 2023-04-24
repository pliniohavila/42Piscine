#include "stdio.h"

char    *ft_strupcase(char *str)
{
    char    tmp;
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] >= 97) && (str[i] <= 122))
        {
            tmp = (str[i] - 32);
            str[i] = tmp;
        }
        printf("%c, ", str[i]);
        i++;
    }
    str[i] = '\0';
    printf(" - %s - \n, ", str);
    return (str);
}

int     main(void)
{
    char    src[6] = "STRing";
    char    *struped;

    printf("Before: %s\n", src);
    struped = ft_strupcase(src);
    printf("After: %s\n", struped);

    return (0);
}