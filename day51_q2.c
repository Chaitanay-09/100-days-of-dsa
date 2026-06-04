class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (p->val < root->val && q->val < root->val)
                root = root->left;     // go left
            else if (p->val > root->val && q->val > root->val)
                root = root->right;    // go right
            else
                return root;           // found LCA
        }
        return NULL;
    }
};