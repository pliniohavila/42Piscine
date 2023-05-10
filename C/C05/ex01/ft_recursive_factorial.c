#include "stdio.h"

int     ft_atoi(char *str)
{
    int     result;
    int     count_subtractions;

    result = 0;
    for (int i = 0; check_is_int(str[i]) != 0; i++)
    {
        if (str[i] == '-')
        {
            count_subtractions++;
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            result = result * 10 + (str[i] - '0');
        }
    }
 
    if ((count_subtractions % 2) != 0)
    {
        result *= (-1);
    }

    return result;
}

int     ft_recursive_fatorial(int nb)
{
    
}