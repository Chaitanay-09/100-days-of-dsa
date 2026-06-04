class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
    
private:
    void solve(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        result.push_back(node->val);  // Visit root first
        solve(node->left, result);    // Then left subtree
        solve(node->right, result);   // Then right subtree
    }
};