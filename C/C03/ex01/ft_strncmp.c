#include <stdio.h>

int     ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int     i;

    i = 0;
    while ((i < n) && s1[i] != '\0')
    {
        if ((s1[i] - s2[i]) < 0)
        {
            return (-1);
        }
        else if ((s1[i] - s2[i]) > 0)
        {
            return (1);
        }
        i++;
    }


    return (0);
}


int     main (void) 
{
    char a[] = "aeiou";
    char b[] = "aeioo";

    printf(" %d \n", ft_strncmp(a, b, 2));
   
    return(0);
}