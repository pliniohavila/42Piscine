int     i;
    int     *k;
    int     *nb;
    t_list  *list;
    t_list  *last;
    
    list = NULL;
    i = 1;
    while (i < 4)
    {
        if ((k = malloc(sizeof(int))) == NULL)
            return (1);
        *k = i++;
        ft_list_push_front(&list, k);
    }
    ft_list_foreach(list, print_elem_data);
    printf("Size: %d\n", ft_list_size(list));
    last = ft_list_last(list);
    printf("Last element: ");
    print_elem_data(last->data);
    if ((nb = malloc(sizeof(int))) == NULL)
        return (1);
    *nb = 42;
    printf("Add element in back\n");
    ft_list_push_back(&list, nb);
    ft_list_foreach(list, print_elem_data);
    printf("Size: %d\n", ft_list_size(list));
    ft_list_clear(&list, free_fct);
    if (list == NULL)
        printf("List empty");
    return(0);