#include "stdio.h"

#define BUF_SIZE 10

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    if (dest == NULL)
        return NULL;

    char    *dest_start;
    unsigned int     i;

    dest_start = dest;
    i = 0;
    while ((src[i] != '\0') && (i < n))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (dest_start);
}

int     main(void)
{
    char    *src;
    char    dest[BUF_SIZE];
    int     size;

    src = "If a NUL character";
    size = BUF_SIZE;
    printf("Before:> src: %s, dest: %s\n", src, dest);
    ft_strncpy(dest, src, size);
    printf("After:> src: %s, dest: %s\n", src, dest);

    return (0);
}
