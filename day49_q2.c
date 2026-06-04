class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // अगर tree खाली है तो नया node बनाओ
        if (root == NULL) {
            return new TreeNode(val);
        }

        // अगर val छोटा है → left में डालो
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } 
        // अगर val बड़ा है → right में डालो
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};