#include <stdio.h>
#include <stdlib.h>

// Sort by position descending
int cmp(const void *a, const void *b) {
    return ((int*)b)[0] - ((int*)a)[0];
}

int carFleet(int target, int cars[][2], int n) {
    if (n == 0) return 0;

    // Sort by position descending (closest to target first)
    qsort(cars, n, sizeof(cars[0]), cmp);

    int fleets = 0;
    double maxTime = 0.0;  // slowest time seen so far (leads the fleet)

    for (int i = 0; i < n; i++) {
        int pos   = cars[i][0];
        int speed = cars[i][1];

        double time = (double)(target - pos) / speed;

        if (time > maxTime) {
            // This car can't catch the car ahead → new fleet
            fleets++;
            maxTime = time;
        }
        // else: catches up → joins existing fleet, ignored
    }

    return fleets;
}

int main() {
    // Test 1: classic
    int cars1[][2] = {{10,2},{8,4},{0,1},{5,1},{3,3}};
    int n1 = 5, target1 = 12;
    printf("Target: %d\n", target1);
    printf("Cars (pos, speed): ");
    for (int i = 0; i < n1; i++) printf("[%d,%d] ", cars1[i][0], cars1[i][1]);
    printf("\nFleets: %d\n\n", carFleet(target1, cars1, n1));

    // Test 2: all same speed
    int cars2[][2] = {{3,2},{6,2},{9,2}};
    int n2 = 3, target2 = 15;
    printf("Target: %d\n", target2);
    printf("Cars (pos, speed): ");
    for (int i = 0; i < n2; i++) printf("[%d,%d] ", cars2[i][0], cars2[i][1]);
    printf("\nFleets: %d\n\n", carFleet(target2, cars2, n2));

    // Test 3: each car is its own fleet
    int cars3[][2] = {{0,6},{4,7},{8,3}};
    int n3 = 3, target3 = 10;
    printf("Target: %d\n", target3);
    printf("Cars (pos, speed): ");
    for (int i = 0; i < n3; i++) printf("[%d,%d] ", cars3[i][0], cars3[i][1]);
    printf("\nFleets: %d\n", carFleet(target3, cars3, n3));

    return 0;
}