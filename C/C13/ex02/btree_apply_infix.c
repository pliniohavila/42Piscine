void        btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->item);
    ft_putstr(" ");
    btree_apply_infix(root->right, applyf);
}