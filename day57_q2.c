void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;
    
    while (curr != NULL) {
        if (curr->left != NULL) {
            // Find rightmost node of left subtree
            struct TreeNode* rightmost = curr->left;
            while (rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            
            // Attach current right subtree to rightmost
            rightmost->right = curr->right;
            
            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}