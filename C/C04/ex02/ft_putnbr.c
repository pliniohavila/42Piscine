#include "unistd.h"
#include "stdio.h"

#define MAX_BUFFER 127


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
    {
        abs_nb = (nb * (-1));
    } else 
    {
        abs_nb = nb;
    }
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

int     main(void)
{
    putnbr(47);
    printf("\n");
    putnbr(4);
    printf("\n");
    putnbr(-1984);

    return (0);
}