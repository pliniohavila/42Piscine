#include "stdio.h"

#define BUF_SIZE 10

char    *ft_strcpy(char *dest, char *src)
{
    if (dest ==  NULL)
        return NULL;
    char    *dest_start;    

    dest_start = dest;
    while(*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
    return (dest_start);
}

int     main(void)
{
    char    *src;
    char    dest[BUF_SIZE];
    
    src = "Miles";
    printf("Before:> src: %s, dest: %s\n", src, dest);
    ft_strcpy(dest, src);
    printf("After:> src: %s, dest: %s\n", src, dest);
}