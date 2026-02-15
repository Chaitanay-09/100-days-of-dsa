void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int r[rows];
    int c[cols];

    // initialize markers
    for (int i = 0; i < rows; i++) r[i] = 0;
    for (int j = 0; j < cols; j++) c[j] = 0;

    // step 1: mark rows & cols that contain 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                r[i] = 1;
                c[j] = 1;
            }
        }
    }

    // step 2: set zeroes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (r[i] == 1 || c[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
