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
void        ft_list_clear(t_list **begin_list, void (*free_fct)(void *));
int         ft_list_size(t_list *begin_list);
t_list      *ft_list_last(t_list *begin_list);
void        free_fct(void *);
void        print_elem_data(void *data);


#endif