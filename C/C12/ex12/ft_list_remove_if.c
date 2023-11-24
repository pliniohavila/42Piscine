void        ft_list_remove_if(t_list **s, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list      *current;
    t_list      *prev;
    t_list      *tmp;

    current = *s;
    prev = NULL;
    tmp = NULL;
    while (current != NULL)
    {
        if ((cmp(current->data, data_ref)) == 0) 
        {
            if (prev == NULL) 
            {
                tmp = current;
                *s = (*s)->next;
                current = *s;
                tmp->data = NULL;
                free_fct(tmp);
            }
            else 
            {
                tmp = current;
                current = current->next;
                prev->next = current;
                tmp->data = NULL;
                free_fct(tmp);
                prev = current;
                
            }
        }
        else 
        {   
            prev = current;
            current = current->next;
        }
    }
}