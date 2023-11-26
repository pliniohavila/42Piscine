void        ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list      *i;
    t_list      *k;
    void        *tmp;

    i = *begin_list;   
    while (i != NULL)
    {
        k = *begin_list;;
        while (k->next != NULL) 
        {
            if ((cmp(k->data, k->next->data)) > 0)
            {
                tmp = k->data;
                k->data = k->next->data;
                k->next->data = tmp;
            }
            k = k->next;
        }
        i = i->next;
    }
}
