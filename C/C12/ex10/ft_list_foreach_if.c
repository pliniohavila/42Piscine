void        ft_list_foreach_if(t_list *begin_list, void (*f)(void *), 
                void *data_ref, int(*cmp)())
{
    t_list  *current;

    current = begin_list;
    while (current != NULL)
    {
        if ((cmp(current->data, data_ref)) == 0)
            f(current->data);
        current = current->next;
    }
}
