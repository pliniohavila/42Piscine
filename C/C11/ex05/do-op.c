#include "do-op.h"

int     main(int argc, char **argv)
{
    int     nb1;
    int     nb2;
    int     res;

    if (argc < 4)
        return (1);
    nb1 = ft_atoi(argv[1]);
    nb2 = ft_atoi(argv[3]);
    res = 0;
    if (ft_strcmp(argv[2], "+") == 0) 
        res = (*operators[0])(nb1, nb2);
    else if (ft_strcmp(argv[2], "-")  == 0) 
        res = (*operators[1])(nb1, nb2);
    else if (ft_strcmp(argv[2], "*")  == 0) 
        res = (*operators[2])(nb1, nb2);
    else if (ft_strcmp(argv[2], "/")  == 0) 
    {
        if (nb2 == 0)
        {
            ft_putstr("Stop : division by zero\n");
            return (1);
        }
        res = (*operators[3])(nb1, nb2);
    }
    else if (ft_strcmp(argv[2], "%") == 0) 
    {
        if (nb2 == 0)
        {
            ft_putstr("Stop : modulo by zero\n");
            return (1);
        }
        res = (*operators[4])(nb1, nb2);
    }      
    ft_putnbr(res);
    ft_putstr("\n");
    return (0);
}

int     sum(int a, int b) 
{
    return (a + b); 
}
int     sub(int a, int b)
{
    return (a - b);
}
int     mul(int a, int b)
{
    return (a * b);
}
int     div(int a, int b)
{
    return (a / b);
}
int     mod(int a, int b)
{
    return (a % b);
}

int     check_is_int(char ch)
{
    if ((ch == 32) || (ch == '\n') || (ch == '\t') || 
        (ch == '\v') || (ch == '\f') || (ch == '\r') || 
        (ch == '-') || (ch == '+'))
        return (1);
    else if (ch >= '0' && ch <= '9')
        return (1);
    return (0);
}

int     ft_atoi(char *str)
{
    int     result;
    int     count_neg;
    int     i;

    result = 0;
    count_neg = 0;
    i = 0;
    while (check_is_int(str[i]) != 0)
    {
        if (str[i] == '-')
            count_neg++;
        if ((str[i] >= '0') && (str[i] <= '9'))
            result = result * 10 + (str[i] - '0');
        i++;
    }
    if ((count_neg % 2) != 0)
        result *= (-1);
    return (result);
}

char    *ft_strcpy(char *dest, char *src)
{
    char    *dest_start;    

    if (dest ==  NULL)
        return NULL;
    dest_start = dest;
    while(*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return (dest_start);
}

int     ft_strcmp(char *s1, char *s2)
{
    unsigned char   c1;
    unsigned char   c2;

    while (*s1 != '\0')
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return (c1 < c2 ? -1 : 1);
    }
    return (0);
}

void    ft_putstr(char *str)
{
    while (*str != '\0') 
        write(1, str++, 1);
}

void    ft_putnbr(int nb)
{
    int     abs_nb;
    int     control;
    int     mod;
    char    nb_as_str[MAX_BUFFER];

    control = MAX_BUFFER;
    nb_as_str[control] = '\0';
    control--;
    if (nb < 0)
        abs_nb = (nb * (-1));
    else 
        abs_nb = nb;
    while (abs_nb != 0)
    {
        mod = (abs_nb % 10);
        nb_as_str[control] = (mod + 48);
        abs_nb = (abs_nb - mod) / 10;
        control--;
    }
    if (nb < 0)
    {
        nb_as_str[control] = '-';
        control--;
    }
    ft_putstr(&nb_as_str[control + 1]);
}