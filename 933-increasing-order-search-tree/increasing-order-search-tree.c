struct TreeNode* current;

void inorder(struct TreeNode* root) {

    if (root == NULL)
        return;

    // Visit left subtree
    inorder(root->left);

    // Remove left child
    root->left = NULL;

    // Connect previous node to current node
    current->right = root;
    current = root;

    // Visit right subtree
    inorder(root->right);
}

struct TreeNode* increasingBST(struct TreeNode* root) {

    struct TreeNode dummy;
    dummy.right = NULL;

    current = &dummy;

    inorder(root);

    return dummy.right;
}