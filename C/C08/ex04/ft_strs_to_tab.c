#include <stdio.h>
#include <stdlib.h>

#include "ft_stock_str.h"

int     ft_strlen(char *str)
{
    register int    i;

    i = 0;
    while(str[i] != '\0')
        i++;

    return (i);
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

struct      s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    register int    i;
    t_stock_str     *stock_str;

    stock_str = malloc(sizeof(t_stock_str) * (ac + 1));
    if (stock_str == NULL)
        return NULL;

    i = 0;
    while (i < ac)
    {
        stock_str[i].size = ft_strlen(av[i]);
        stock_str[i].str = (char*)malloc(sizeof(char) * (stock_str[i].size + 1));
        if (stock_str[i].str == NULL)
            goto error;
        ft_strcpy(stock_str[i].str, av[i]);
        stock_str[i].copy = (char*)malloc(sizeof(char) * (stock_str[i].size + 1));
        if (stock_str[i].copy == NULL)
            goto error;
        ft_strcpy(stock_str[i].copy, av[i]);
        
        i++;
    }

    stock_str[i].str = 0;

    return (stock_str);

error: 
    i = 0;
    while (*stock_str[i].str != '\0')
    {
        free(stock_str[i].str);
        free(stock_str[i].copy);
        i++;
    }
        
    free(stock_str);

    return NULL;
}

int     main(void)
{
    int         ac;
    register    int i;
    char        *av[] = {"ITSA4", "PETR3", "VALE3", "ABEV3"}; 

    ac = sizeof(av)/sizeof(*av);
    t_stock_str *stock_str  = ft_strs_to_tab(ac, av);
    if (stock_str == NULL)
        return (-1);

    i = 0;
    while (stock_str[i].str != 0)
    {
        printf("STR: %s - COPY: %s\n", stock_str[i].str, stock_str[i].copy);
        i++;
    }

    return (0);
}