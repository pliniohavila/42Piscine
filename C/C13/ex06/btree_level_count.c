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