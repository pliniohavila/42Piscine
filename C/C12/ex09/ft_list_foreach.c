#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"


int     main(void)
{
    int     nb;
    t_list  *list;

    nb = 42;
    list = ft_create_elem(&nb);
    if (list == NULL)
        return (1);
    field_list(&list);
    ft_list_foreach(list, print_elem_data);
    return(0);
}


void        ft_list_push_front(t_list **begin_list, void *data)
{
    t_list      *elem;

    elem = ft_create_elem(data);
    if (elem == NULL)
        return;
    elem->next = (*begin_list)->next;
    (*begin_list)->next = elem;
}

t_list      *ft_create_elem(void *data)
{
    t_list      *elem;

    elem = (t_list*)malloc(sizeof(t_list));
    if (elem == NULL)
        return NULL;
    elem->next = NULL;
    elem->data = data;
    return (elem);
}

void        ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list      *list_ptr;

    list_ptr  = begin_list;
    while (list_ptr != NULL)
    {
        f(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}

void        print_elem_data(void *data)
{
    printf("Data: %d\n", *(int*)data);
}

void        field_list(t_list **begin_list)
{
    int     data[5];
    int     i;

    data[0] = 56;
    data[1] = 21;
    data[2] = 3;
    data[3] = 22;
    data[4] = 9;
    i = 0;
    while (i < 5)
        ft_list_push_front(begin_list, &data[i++]);
}