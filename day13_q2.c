int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    int total = m * n;
    *returnSize = total;

    int* result = (int*)malloc(sizeof(int) * total);

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int k = 0;

    while (top <= bottom && left <= right) {

        // left -> right
        for (int i = left; i <= right; i++)
            result[k++] = matrix[top][i];
        top++;

        // top -> bottom
        for (int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            // right -> left
            for (int i = right; i >= left; i--)
                result[k++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            // bottom -> top
            for (int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }

    return result;
}
