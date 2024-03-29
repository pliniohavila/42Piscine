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
    ft_list_clear(&list, free_fct);
    ft_list_foreach(list, print_elem_data);
    if (list == NULL)
        printf("List empty");
    return(0);
}

void        ft_list_push_front(t_list **begin_list, void *data)
{
    t_list      *elem;
    t_list      *current;

    elem = ft_create_elem(data);
    if (elem == NULL)
        return;
    if (*begin_list == NULL)
    {
        *begin_list = elem;
    }
    else 
    {
        current = *begin_list;
        while (current->next != NULL) {
            current = current->next;
        }
        elem->next = current->next;
        current->next = elem;
    }
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

    if (!begin_list)
        return;
    list_ptr  = begin_list;
    while (list_ptr != NULL)
    {
        f(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}

void        ft_list_clear(t_list **begin_list, void (*free_fct)(void *))
{
    t_list      *current;

    if (!begin_list || !(*begin_list))
        return;
    while (*begin_list)
    {
        
        current = *begin_list;
        *begin_list = (*begin_list)->next;
        free_fct(current->data);
        free_fct(current);
    }
    *begin_list = NULL;
}

void        free_fct(void *ptr)
{
    free(ptr);
}

void        print_elem_data(void *data)
{
    printf("Data: %d\n", *(int*)data);
}
