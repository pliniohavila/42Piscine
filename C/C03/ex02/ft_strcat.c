#include "stdio.h"

int     ft_strlen(char *);

char    *ft_strcat(char *dest, char *src)
{   
    int     i;
    int     j;

    i = (ft_strlen(dest));
    j = 0;
    while (dest[i] == '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    return dest;
}

int     main(void)
{
    char    src[] = "Legolas ";
    char    dest[30] = "Gimli";
    printf("Before: %s\n", dest);
    ft_strcat(dest, src);
    printf("After: %s\n", dest);
}

int     ft_strlen(char *str) {
    int     len; 

    len = 0;
    while (*str || *str == '\0')
    {
        len++;
        str++;
    }

    return (len);
}
