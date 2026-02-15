#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];
    int sum = 0;

    // input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // primary diagonal sum
    for(int i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("%d", sum);

    return 0;
}
