#include "ft_list.h"

t_list      *ft_list_push_strs(int size, char **strs)
{
    int         i;
    t_list      *list_strs;

    list_strs = NULL;
    i = 0;
    while (i < size)
    {
        ft_list_push_front(&list_strs, strs[i]);
        i++;
    }
    return(list_strs);
}