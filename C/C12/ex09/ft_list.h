#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct          s_list
{
    struct s_list       *next;
    void                *data;
}                       t_list;

t_list      *ft_create_elem(void *data);
void        ft_list_push_front(t_list **begin_list, void *data);
void        ft_list_foreach(t_list *begin_list, void (*f)(void *));
void        print_elem_data(void *data);
void        field_list(t_list **begin_list);

#endif