#include <stdio.h>

void dfs(int** image, int row, int col, int sr, int sc, int oldColor, int newColor) {
    // Boundary check
    if (sr < 0 || sc < 0 || sr >= row || sc >= col)
        return;

    // If color doesn't match or already filled
    if (image[sr][sc] != oldColor || image[sr][sc] == newColor)
        return;

    // Fill color
    image[sr][sc] = newColor;

    // Move in 4 directions
    dfs(image, row, col, sr+1, sc, oldColor, newColor);
    dfs(image, row, col, sr-1, sc, oldColor, newColor);
    dfs(image, row, col, sr, sc+1, oldColor, newColor);
    dfs(image, row, col, sr, sc-1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    int oldColor = image[sr][sc];

    if (oldColor != color) {
        dfs(image, imageSize, imageColSize[0], sr, sc, oldColor, color);
    }

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}