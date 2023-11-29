void        btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    applyf(root->item);
    ft_putstr(" ");
    btree_print_nodes(root->left);
    btree_print_nodes(root->right);
}