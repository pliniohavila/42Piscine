
void        ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list      *current;

    current = *begin_list1;
    while (current->next != NULL)
        current = current->next;
    if (current->next == NULL)
        current->next = begin_list2;
    return;
}