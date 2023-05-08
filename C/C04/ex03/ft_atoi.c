#include "stdio.h"

int     check_is_int(char ch)
{
    if ((ch == 32) || (ch == '-') || (ch == '+'))
    {
        return (1);
    } 
    else if (ch >= '0' && ch <= '9')
    {
        return (1);
    }

    return (0);
}

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

int     main(void)
{
    char    str[] = " ---+--+1234ab56";
    int     r;
    
    r = ft_atoi(str);
    printf("%d\n", r);

    return (0);
}