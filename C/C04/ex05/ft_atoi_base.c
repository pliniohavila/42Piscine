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
        if ((str[i] == '-') || (str[i] == '+') || (str[i] == ' '))
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

int     check(char ch)
{
    if ((ch == 32) || (ch == '-') || (ch == '+'))
    {
        return (1);
    } 

    return (0);
}

int     include(char *seq, char ch)
{
    for (int i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == ch) 
        {
            return (1);
        }
    }
    return (0);
}

int ft_atoi_base(char *str, char *base)
{
    if (!(valid_base(base)))
        return (0);

    int     result;
    int     i;
    int     len_base;
    int     power;
    int     digit_value;
    int     start_str_valid;
    int     count_subtractions;

    result = 0;
    i = 0;
    len_base = ft_strlen(base);
    power = 1;
    while (check(str[i]))
    {
        i++;
        if (str[i] == '-')
        {
            count_subtractions++;
        }
    }
    // Save on start valid number representation as string
    start_str_valid = i;
    while (include(base, str[i]) == 1)
    {
        i++;
    }

    for (int k = (i - 1); k >= start_str_valid; k--)
    {
        if (str[k] >= '0' && str[k] <= '9') 
        {
            digit_value = str[k] - '0';
        } 
        else if (str[k] >= 'a' && str[k] <= 'z') 
        {
            digit_value = str[i] - 'a' + 10;
        } 
        else if (str[k] >= 'A' && str[k] <= 'Z') 
        {
            digit_value = str[k] - 'A' + 10;
        } 

        result += digit_value * power;
        power *= len_base;
    }
 
    if ((count_subtractions % 2) != 0)
    {
        result *= (-1);
    }

    return result;
}


int     main(void)
{
    char    *b0;
    char    *b1;
    char    *b2;

    b0 = "0123456789";
    b1 = "poneyvif";
    b2 = "0123456789ABCDEF";

    printf("1: %d\n", ft_atoi_base("125", b0));
    // printf("2: %d\n", ft_atoi_base("-125", b0));
    printf("3: %d\n", ft_atoi_base("--1A7poqw", b2));
    printf("4: %d\n", ft_atoi_base("--7Dpoqw", b2));
    printf("5: %d\n", ft_atoi_base("125", b1));
    // ft_atoi_base("-125", b2);
}