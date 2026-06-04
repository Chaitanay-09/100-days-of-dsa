/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

struct Queue {
    struct TreeNode* data[2000];
    int front;
    int rear;
};

void push(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* pop(struct Queue* q) {
    return q->data[q->front++];
}

int size(struct Queue* q) {
    return q->rear - q->front;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int*)malloc(2000 * sizeof(int));
    returnColumnSizes = (int)malloc(2000 * sizeof(int));

    struct Queue q;
    q.front = 0;
    q.rear = 0;

    push(&q, root);

    while(size(&q) > 0) {
        int levelSize = size(&q);

        result[returnSize] = (int)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for(int i = 0; i < levelSize; i++) {
            struct TreeNode* node = pop(&q);
            result[*returnSize][i] = node->val;

            if(node->left) push(&q, node->left);
            if(node->right) push(&q, node->right);
        }

        (*returnSize)++;
    }

    return result;
}