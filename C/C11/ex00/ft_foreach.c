#include "unistd.h"

#define AR_LENGTH(arr) sizeof(arr) / sizeof(arr[0])
#define MAX_BUFFER 30

void    ft_foreach(int *tab, int length, void(*f)(int));
void    putnbr(int nb);
void    ft_putstr(char *str);

int     main(void)
{
    int     tab[] = {55, 12, 2, 3, 8};
    int     length;

    length = AR_LENGTH(tab);
    ft_foreach(tab, length, &putnbr);
    return (0);
}


void ft_foreach(int *tab, int length, void(*f)(int))
{
    int     i;

    i = 0;
    while(i < length)
    {
        f(tab[i]);
        write(1, ", ", 2);
        i++;
    }
    write(1, "\n", 1);
}

void     ft_putstr(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    putnbr(int nb)
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