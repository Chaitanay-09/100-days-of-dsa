#include <stdio.h>

// Check if we can allocate books to m students with max limit
int canAllocate(int* books, int n, int m, long long limit) {
    int students = 1;
    long long pagesAssigned = 0;

    for (int i = 0; i < n; i++) {
        if (pagesAssigned + books[i] <= limit) {
            pagesAssigned += books[i];   // Give book to current student
        } else {
            students++;                  // New student needed
            pagesAssigned = books[i];    // Start fresh with this book

            if (students > m) return 0; // Exceeded student count
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    long long total = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        total += books[i];
        if (books[i] > maxVal) maxVal = books[i];
    }

    // Edge case: more students than books
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    long long low = maxVal;   // min possible answer
    long long high = total;   // max possible answer
    long long result = total;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canAllocate(books, n, m, mid)) {
            result = mid;       // feasible, try smaller limit
            high = mid - 1;
        } else {
            low = mid + 1;      // not feasible, increase limit
        }
    }

    printf("%lld\n", result);
    return 0;
}