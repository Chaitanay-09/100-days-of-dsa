int cmp(const void *a, const void *b) {
    return ((int*)b)[0] - ((int*)a)[0];  // descending by position
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    // Pair up position and speed, then sort by position descending
    int cars[positionSize][2];
    for (int i = 0; i < positionSize; i++) {
        cars[i][0] = position[i];
        cars[i][1] = speed[i];
    }
    qsort(cars, positionSize, sizeof(cars[0]), cmp);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        double time = (double)(target - cars[i][0]) / cars[i][1];

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    return fleets;
}