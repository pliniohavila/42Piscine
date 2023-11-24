#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int     main(void)
{
    t_list  *list;
    t_list  *current;
    char    *strs[4];
    t_list   *at;

    strs[0] = "Ecole42";   
    strs[1] = "Push";   
    strs[2] = "Compiler";   
    strs[3] = "Action That";   
    list = ft_list_push_strs(4, strs);

    current = list;
    printf("Size: %d\n", ft_list_size(list));
    while (current)
    {
        printf("%s - ", (char*)current->data);
        current = current->next;
    }
    printf("\n");
    at = ft_list_at(list, 2);
    printf("List at[2]: %s\n", (char*)at->data);
    ft_list_clear(&list, free_fct);
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
        while (current->next != NULL)
            current = current->next;
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
        // free_fct(current->data);
        current->data = NULL;
        free_fct(current);
    }
    *begin_list = NULL;
}

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

t_list      *ft_list_last(t_list *begin_list)
{
    t_list      *current;

    current = begin_list;
    while (current->next != NULL)
        current = current->next;
    return (current);
}

void        ft_list_push_back(t_list **begin_list, void *data)
{
    t_list      *elem;

    elem = ft_create_elem(data);
    if (elem == NULL)
        return;
    elem->next = *begin_list;
    *begin_list = elem;
}

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

t_list      *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int    i;
    t_list          *elem;

    i = 0;
    elem = begin_list;  
    while (elem)
    {
        if (i == nbr)
            return (elem);
        i++;
        elem = elem->next;
    }
    return NULL;
}

void        free_fct(void *ptr)
{
    free(ptr);
}

void        print_elem_data(void *data)
{
    printf("Data: %d\n", *(int*)data);
}