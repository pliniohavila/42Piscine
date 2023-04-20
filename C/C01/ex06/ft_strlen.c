#include "stdio.h"

int     ft_strlen(char *str) {
    int     len; 

    len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }

    return (len);
}

int     main(void)
{
    char    *str;
    int     len_str;

    str = "strlen";
    len_str = ft_strlen(str);
    printf("Len: %d\n", len_str);
    printf("String: %s\n", str);
    return (0);
}
