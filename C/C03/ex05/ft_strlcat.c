#include "stdio.h"

static inline int     ft_strlen(char *);

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{   
    unsigned int    len_dest;
    unsigned int    i;
    unsigned int    j;
    unsigned int    len_src;
    unsigned int    empty_space;

    len_dest = ft_strlen(dest);
    len_src = ft_strlen(src);
    empty_space = (size - len_dest);
    if (empty_space > 0)
    {
        i = len_dest;
        j = 0;
        while (j < empty_space)
        {
            dest[i] = src[j];
            i++;
            j++;
        }
    }
    return (len_src + len_dest);
}

int     main(void)
{
    char    src[] = "Legolas";
    char    dest[10] = "Gimli ";
    unsigned int    r;

    printf("Before: %s\n", dest);
    r = ft_strlcat(dest, src, 10);
    printf("After: %s\n", dest);
    printf("Len: %d\n", r);


    return (0);
}

static inline int     ft_strlen(char *str) {
    int     len; 

    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    return (len);
}
