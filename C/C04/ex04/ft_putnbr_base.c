#include "stdio.h"
#include "unistd.h"

int     ft_strlen(char *str)
{
    int     count;

    count = 0;
    while (str[count] != '\0')
    {
        count++;
    }

    return count;
}

int     valid_base(char *str)
{
    if (ft_strlen(str) < 2)
        return (0);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] == '-') || (str[i] == '+'))
        {
            return (0);
        }
        for (int j = i + 1; str[j] != '\0'; j++)
        {
            if (str[j] == str[i])
                return (0);
        }
    }

    return (1);
}

void    ft_putnbr_base(int nb, char *base)
{
    if (valid_base(base) == 1)
    {
        int     i;
        int     len_base;
        int     mod;
        int     digits[32];
        int     abs;

        i = 32;
        len_base = ft_strlen(base);
        abs = nb >= 0 ? nb : (nb * (-1));

        while (abs != 0)
        {
            mod = abs % len_base;            
            digits[i] = base[mod];
            abs = (abs - mod) / len_base;
            i--;
        }

        if (nb < 0)
        {
            digits[i] = 45;
            i--;
        }
        
        for (int k = (i + 1); k <= 32; k++)
        {
            write(1, &digits[k], 1);
        }
    }
    printf("\n");
}

int     main(void)
{
    char    *b0;
    char    *b1;
    char    *b2;

    b0 = "0123456789";
    b1 = "poneyvif";
    b2 = "0123456789ABCDEF";

    ft_putnbr_base(125, b0);
    ft_putnbr_base(-125, b0);
    ft_putnbr_base(125, b1);
    ft_putnbr_base(125, b2);
    ft_putnbr_base(-125, b2);
}