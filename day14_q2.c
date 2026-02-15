void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, temp;

    // Step 1: transpose
    for (i = 0; i < matrixSize; i++) {
        for (j = i + 1; j < matrixSize; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: reverse each row
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixSize / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;
        }
    }
}
