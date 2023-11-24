void        ft_list_reverse(t_list **begin_list) 
{
    t_list     *prev;
    t_list     *next;
    t_list     *current;

    prev = NULL;
    current = *begin_list;
    while (current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin_list = prev;
}
