#ifndef FT_BTREE_H
#define FT_BTREE_H

#define VECTOR_SIZE(n)  sizeof(n)/sizeof(n[0])
#define LIST_LEN 5 

typedef struct      s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
}                   t_btree;

t_btree             *btree_create_node(void *item);
t_btree             *btree_insert_node(t_btree *btree, void *item);
t_btree             *btree_make(t_btree *btree, char **itens, int len);
void                btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void                btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void                btree_apply_infix(t_btree *root, void (*applyf)(void *));
void                btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void                *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
void                btree_print_node(void *item);
void                ft_putstr(char *str);
int                 ft_strcmp(char *s1, char *s2);
int                 voidcmp(void *s1, void *s2);



#endif