// Check if capacity 'cap' can ship all packages within 'days' days
int canShip(int* weights, int n, int days, int cap) {
    int daysNeeded = 1;
    int load = 0;

    for (int i = 0; i < n; i++) {
        if (load + weights[i] <= cap) {
            load += weights[i];       // Add to today's load
        } else {
            daysNeeded++;             // New day needed
            load = weights[i];        // Start fresh

            if (daysNeeded > days) return 0;
        }
    }
    return 1;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;

    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low) low = weights[i];  // max single weight
        high += weights[i];                       // total weight
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            result = mid;        // feasible, try less capacity
            high = mid - 1;
        } else {
            low = mid + 1;       // not feasible, need more capacity
        }
    }

    return result;
}