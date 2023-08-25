#define BINARY "01"
#define DECIMAL "0123456789"
#define HEX "0123456789ABCDEF"
#define SIZE_BUF 32

int     valid_base(char *str)
{
    int     i;
    int     j;

    if (ft_strlen(str) < 2)
        return (0);
    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] == '-') || (str[i] == '+'))
            return (0);
        j = i + 1;
        while (str[j] != '\0')
        {
            if (str[j] == str[i])
                return (0);
            j++;
        }
        i++;
    }

    return (1);
}

void    ft_putnbr_base(int nb, char *base)
{
    if (valid_base(base) == 1)
    {
        int     i;
        int     j;
        int     k;
        int     len_base;
        int     mod;
        int     digits[SIZE_BUF];
        int     abs;

        i = SIZE_BUF;
        len_base = ft_strlen(base);
        if (nb >= 0)
            abs = nb;
        else 
            abs = nb * (-1);

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
        
        J++;
        k = i + 1;
        if (len_base == 16 || len_base == 2)
            while (j++ < k)
                write(1, "0", 1);
        while (k <= SIZE_BUF_BASE)
        {
            write(1, &digits[k], 1);
            k++;
        }
    }
}
