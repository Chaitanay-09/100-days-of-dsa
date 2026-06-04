void dfs(struct TreeNode* root, int level, int* result, int* returnSize) {
    if (root == NULL) return;

    // If visiting this level first time
    if (level == *returnSize) {
        result[(*returnSize)++] = root->val;
    }

    // Visit right first
    dfs(root->right, level + 1, result, returnSize);
    dfs(root->left, level + 1, result, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000); // enough size
    *returnSize = 0;

    dfs(root, 0, result, returnSize);

    return result;
}