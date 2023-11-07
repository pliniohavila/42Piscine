#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int     main(void)
{
    int   i;
    int   *k;
    t_list  *list;
    
    list = NULL;
    i = 1;
    while (i < 4)
    {
      k = malloc(sizeof(int));
      *k = i++;
      ft_list_push_front(&list, k);
    }
    ft_list_foreach(list, print_elem_data);
    ft_list_clear(list, &free_fct);
    ft_list_foreach(list, print_elem_data);
    return(0);
}

void        print_elem_data(void *data)
{
    printf("Data: %d\n", *(int*)data);
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
    elem->data = malloc(sizeof(int));
    if (elem>data == NULL)
        return NULL;
    elem->next = NULL;
    elem->data = data;
    return (elem);
}