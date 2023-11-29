#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"


int     main(void)
{
    t_btree     *btree;
    int         len;
    int     itens[] = { 11, 0, 2, 38, 15, 8, };

    len = VECTOR_SIZE(itens);
    btree = NULL;
    btree = btree_make(btree, itens, len);
    btree_print_nodes(btree);
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
        if (*(int*)item < *(int*)btree_node->item)
            btree_node->left = btree_insert_node(btree_node->left, item);
        else 
            btree_node->right = btree_insert_node(btree_node->right, item);
    }
    // printf("[btree_insert_node]: %d\n", *(int*)btree_node->item);
    return (btree_node);
}

t_btree     *btree_make(t_btree *btree, int itens[], int len)
{
    int     i;

    i = 0;
    while (i < len)
        btree = btree_insert_node(btree, &itens[i++]);
    return (btree);
}

void        btree_print_nodes(t_btree *node)
{
    if (node == NULL)
        return;
    btree_print_nodes(node->left);
    printf("%d ", *(int*)node->item);
    btree_print_nodes(node->right);
}