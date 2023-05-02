#include "stdio.h"

int     ft_strcmp(char *s1, char *s2)
{
    while (*(s1) != '\0')
    {
        if ((*(s1) - *(s2)) < 0)
        {
            return (-1);
        }
        else if ((*(s1) - *(s2)) > 0)
        {
            return (1);
        }
        s1++;
        s2++;
    }

    return (0);
}

int     main(void)
{
    char a[] = "aeiou";
    char b[] = "aeiao";
    int     r;

    r = ft_strcmp(a, b);
    
    printf("R: %d\n", r);

    return (0);
}