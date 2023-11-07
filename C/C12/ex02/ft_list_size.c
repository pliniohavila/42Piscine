#include "ft_list.h"


int         ft_list_size(t_list *begin_list)
{
    int          i;
    t_list      *current;

    i = 0;
    current = begin_list;
    while (current)
    {
        i++;
        current = current->next;
    }
    return (i);
}
