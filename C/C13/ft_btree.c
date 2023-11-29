#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_btree.h"


int     main(void)
{
    t_btree     *btree;
    // int     itens[] = { 11, 0, 2, 38, 15, 8, };
    char    *itens[LIST_LEN] = {"Ecole42", "Push", "Compiler", "News", "Action"};

    btree = NULL;
    btree = btree_make(btree, itens, LIST_LEN);
    btree_apply_prefix(btree, &btree_print_node);
    printf("\n");
    btree_apply_infix(btree, &btree_print_node);
    printf("\n");
    btree_apply_suffix(btree, &btree_print_node);
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

t_btree     *btree_insert_node(t_btree *btree_node, void *item)
{
    if (btree_node == NULL)
    {
        btree_node = btree_create_node(item);
    }
    else 
    {
        if ((ft_strcmp(item, btree_node->item)) > 0)
            btree_node->left = btree_insert_node(btree_node->left, item);
        else 
            btree_node->right = btree_insert_node(btree_node->right, item);
    }
    // printf("[btree_insert_node]: %d\n", *(int*)btree_node->item);
    return (btree_node);
}

t_btree     *btree_make(t_btree *btree, char **itens, int len)
{
    int     i;

    i = 0;
    while (i < len)
        btree = btree_insert_node(btree, itens[i++]);
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

void        btree_print_node(void *item)
{
    ft_putstr(item);
}

void        ft_putstr(char *str)
{
    while (*str != '\0') 
        write(1, str++, 1);
}

int         ft_strcmp(char *s1, char *s2)
{
    unsigned char   c1;
    unsigned char   c2;

    while (*s1 != '\0')
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
    }
    return (0);
}