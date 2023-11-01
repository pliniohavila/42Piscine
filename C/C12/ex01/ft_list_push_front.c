#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"


t_list      *ft_create_elem(void*);
void        ft_list_push_front(t_list**, void*);

int     main(void)
{
    int     nb;
    int     nb2;
    t_list  *list;

    nb = 42;
    nb2 = 21;
    list = ft_create_elem(&nb);
    if (list == NULL)
        return (1);
    ft_list_push_front(&list, &nb2);
    printf("Data: %d\n", *(int*)list->data);
    printf("Data: %d\n", *(int*)list->next->data);
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