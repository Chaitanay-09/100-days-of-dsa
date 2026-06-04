#include <stdlib.h>

// Helper to create node
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

int preIndex = 0;

struct TreeNode* build(int* preorder, int* inorder, int start, int end) {
    if (start > end)
        return NULL;

    struct TreeNode* root = newNode(preorder[preIndex++]);

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, inIndex - 1);
    root->right = build(preorder, inorder, inIndex + 1, end);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}