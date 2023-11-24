

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