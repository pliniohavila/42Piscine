#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_btree.h"


int     main(void)
{
    t_btree     *btree;
    int         max;
    char        *itens[LIST_LEN] = {"Ecole42", "Push", "Compiler", "News", "Action"};

    btree = NULL;
    btree = btree_make(btree, itens, LIST_LEN);
    max = btree_level_count(btree);
    printf("Max: %d\n", max);
    printf("\n");
    free(btree);
    return (0);
}

t_btree     *btree_create_node(void *item)
{
    t_btree     *node;

    node =  (t_btree*)malloc(sizeof(t_btree));
    if (node == NULL)
        return NULL;
    node->left = NULL;
    node->right = NULL;
    node->item = item;
    return (node);
}

void     btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
    if (*root == NULL)
    {
        *root = btree_create_node(item);
    }
    else 
    {
        if ((cmpf(item, (*root)->item)) > 0)
            btree_insert_data(&(*root)->left, item, cmpf);
        else 
            btree_insert_data(&(*root)->right, item, cmpf);
    }
}

t_btree     *btree_make(t_btree *btree, char **itens, int len)
{
    int     i;

    i = 0;
    while (i < len)
        btree_insert_data(&btree, itens[i++], &voidcmp);
    return (btree);
}

void        btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    applyf(root->item);
    ft_putstr(" ");
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}

void        btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->item);
    ft_putstr(" ");
    btree_apply_infix(root->right, applyf);
}

void        btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);
    applyf(root->item);
    ft_putstr(" ");
}

void        *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
    void    *result;

    if (root == NULL)
        return NULL;
    result = btree_search_item(root->left, data_ref, cmpf);
    if (result != NULL)
        return (result);
    if ((cmpf(data_ref, root->item)) == 0)
        return root->item;
    result = btree_search_item(root->right, data_ref, cmpf);
    return (result);
}

int         btree_level_count(t_btree *root)
{
    int     height_left;
    int     height_right;

    if (root == NULL) return (0);
    height_left = 0;
    height_right = 0;
    height_left = btree_level_count(root->left);
    height_right = btree_level_count(root->right);

    return (1 + max(height_left, height_right));
}

int         max(int nb1, int nb2)
{
    if (nb1 > nb2)
        return (nb1);
    return (nb2);   
}

void        btree_print_node(void *item)
{
    ft_putstr(item);
}

void        ft_putstr(char *str)
{
    while (*str != '\0') 
        write(1, str++, 1);
}

int         voidcmp(void *s1, void *s2)
{
    return (ft_strcmp((char*)s1, (char*)s2));
}

int         ft_strcmp(char *s1, char *s2)
{
    char   c1;
    char   c2;

    while (*s1 != '\0')
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
    }
    return (0);
}