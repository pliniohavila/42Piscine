#include "stdio.h"

int     ft_strlen(char *);

char    *ft_strncat(char *dest, char *src, int nb)
{   
    int     i;
    int     j;

    i = (ft_strlen(dest));
    j = 0;
    while ((dest[i] == '\0') && (j < nb))
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    return dest;
}

int     main(void)
{
    char    src[] = "Legolas";
    char    dest[30] = "Gimli ";
    printf("Before: %s\n", dest);
    ft_strncat(dest, src, 3);
    printf("After: %s\n", dest);

    return (0);
}

static inline int     ft_strlen(char *str) {
    int     len; 

    len = 0;
    while (*str)
    {
        len++;
        str++;
    }

    return (len);
}
