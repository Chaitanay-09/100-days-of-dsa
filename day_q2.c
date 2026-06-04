class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;

        int sum = 0;

        // Check if left child is a leaf
        if (root->left != NULL &&
            root->left->left == NULL &&
            root->left->right == NULL) {
            sum += root->left->val;
        }

        // Recur for left and right subtree
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};