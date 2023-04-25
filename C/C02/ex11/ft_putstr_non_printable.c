#include "unistd.h"
#include "stdio.h"

void    ft_putstr_non_printable(char *str)
{
    char    digits[] = "0123456789abcdef0123456789ABCDEF";
    char    hex_brute[2];
    char    ch;
    int     i;
    int     mod;

    while(*str != '\0')
    {
        if (!((*str >= 32) && (*str < 127)))
        {
            hex_brute[0] = '0';
            hex_brute[1] = '0';
            ch = *str;

            i = 1;
            while (ch != 0)
            {
                mod = (ch % 16);
                hex_brute[i] = digits[mod];
                ch = ((ch - mod) / 16);
                i--;
            }
            write(1, "\\", 1);
            write(1, hex_brute, 2);
        }
        else 
        {
            write(1, str, 1);
        }
        str++;
    }
}

int     main(void)
{
    char    *str;

    str = "Oi\nvoce esta bem?";
    ft_putstr_non_printable(str);

    return(0);
}