#include "stdio.h"

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int     i;

    i = 0;
    while ((src[i] != '\0') || (i < size))
    {
        dest[i] = src[i];
        i++;
    } 

    return (i);
}

int     main(void)
{
    unsigned int     size;
    unsigned int     length;

    size = 8;

    char    src[] = "Utility";
    char    dest[size];
    
    length = ft_strlcpy(dest, src, size);

    printf("Copied '%s' into '%s', length %d\n",
        src,
        dest,
        length
    );
}