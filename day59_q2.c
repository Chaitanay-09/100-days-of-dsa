#include <stdlib.h>

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

int postIndex;

struct TreeNode* build(int* inorder, int* postorder, int start, int end) {
    if (start > end)
        return NULL;

    struct TreeNode* root = newNode(postorder[postIndex--]);

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    // IMPORTANT: build right first
    root->right = build(inorder, postorder, inIndex + 1, end);
    root->left = build(inorder, postorder, start, inIndex - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1);
}