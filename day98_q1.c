#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int mergeIntervals(int intervals[][2], int n, int result[][2]) {
    if (n == 0) return 0;

    // Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int count = 0;
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        // Overlapping: current start <= previous end
        if (intervals[i][0] <= result[count][1]) {
            // Extend end if needed
            if (intervals[i][1] > result[count][1])
                result[count][1] = intervals[i][1];
        } else {
            // No overlap: start new interval
            count++;
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
        }
    }

    return count + 1;  // number of merged intervals
}

void print(int arr[][2], int n, const char *label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++)
        printf("[%d,%d]%s", arr[i][0], arr[i][1], i < n-1 ? ", " : "\n");
}

int main() {
    // Test 1: classic overlapping
    int a[][2] = {{1,3},{2,6},{8,10},{15,18}};
    int n1 = 4, res1[4][2];
    print(a, n1, "Input ");
    int m1 = mergeIntervals(a, n1, res1);
    print(res1, m1, "Merged");

    printf("\n");

    // Test 2: fully contained
    int b[][2] = {{1,10},{2,6},{8,9},{15,18}};
    int n2 = 4, res2[4][2];
    print(b, n2, "Input ");
    int m2 = mergeIntervals(b, n2, res2);
    print(res2, m2, "Merged");

    printf("\n");

    // Test 3: no overlap
    int c[][2] = {{1,2},{3,4},{5,6}};
    int n3 = 3, res3[3][2];
    print(c, n3, "Input ");
    int m3 = mergeIntervals(c, n3, res3);
    print(res3, m3, "Merged");

    return 0;
}