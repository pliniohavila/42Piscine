#include "unistd.h"

void    ft_putstr(char *str)
{
    char    *letter;
    int     space;

    letter = str;
    space = 32;
    while (*letter != '\0') 
    {
        write(1, letter, 1);
        write(1, &space, 1);
        letter++;
    }
}

int     main(void)
{
    char    *str;

    str = "Rudolfino";
    ft_putstr(str);

    return (0);
}