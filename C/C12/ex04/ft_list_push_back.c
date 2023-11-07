#include "ft_list.h"

void        ft_list_push_back(t_list **begin_list, void *data)
{
    t_list      *elem;

    elem = ft_create_elem(data);
    if (elem == NULL)
        return;
    elem->next = *begin_list;
    *begin_list = elem;
}
