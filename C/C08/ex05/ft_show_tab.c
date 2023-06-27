#include <unistd.h>
#include "ft_strs_to_tab.h"

#define MAX_BUFFER 32

void    ft_putstr(char *str)
{
    while (*str != '\0') 
        write(1, str++, 1);
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
    abs_nb = nb < 0 ? -nb : nb;
   
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

void    ft_show_tab(struct s_stock_str *par)
{
    register int i;

    i = 0;
    while (par[i].str != 0)
    {
        ft_putstr(par[i].str);
        ft_putstr("\n");
        putnbr(par[i].size);
        ft_putstr("\n");
        ft_putstr(par[i].copy);
        ft_putstr("\n");
        i++;
    }
}

int     main(void)
{
    int         ac;
    t_stock_str *stock_str;
    char        *av[] = {"ITSA4", "PETR3", "VALE3", "ABEV3"};

    ac = sizeof(av)/sizeof(*av);
    stock_str  = ft_strs_to_tab(ac, av);
    if (stock_str == NULL)
        return (-1);

    ft_show_tab(stock_str);

    return (0);
}