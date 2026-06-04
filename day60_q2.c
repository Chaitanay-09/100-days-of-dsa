int cameras = 0;

int dfs(struct TreeNode* root) {
    if(root == NULL) return 2;
    
    int left = dfs(root->left);
    int right = dfs(root->right);
    
    if(left == 0 || right == 0) {
        cameras++;
        return 1;
    }
    
    if(left == 1 || right == 1) {
        return 2;
    }
    
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    
    if(dfs(root) == 0) {
        cameras++;
    }
    
    return cameras;
}