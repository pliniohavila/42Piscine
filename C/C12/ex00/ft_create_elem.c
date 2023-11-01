#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"


t_list      *ft_create_elem(void*);

int     main(void)
{
    int     nb;
    t_list  *elem;

    nb = 42;
    elem = ft_create_elem(&nb);
    if (elem == NULL)
        return (1);
    printf("Data: %d", *(int*)elem->data);
    free(elem);
    return(0);
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