#include "stdio.h"
#include "stdlib.h"

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
    return dest_start;
}

char    *ft_strdup(char *str)
{
    size_t     i;
    char     *dest;

    if (str == NULL)
        return NULL;

    i = 0;
    while (str[i] != '\0')
        i++;
    
    dest = (char *)malloc(i + 1);
    if (dest == NULL)
        return NULL;
    
    return dest;
}

int     main(int argc, char **argv)
{
    char    *dest;

    if (argc < 1)
        return (-1);

    dest = argv[1];
    printf("Origin: %s\n", argv[1]);
    printf("Copied: %s\n", dest);

    return (0);
}