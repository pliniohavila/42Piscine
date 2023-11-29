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
    return (btree_node);
}