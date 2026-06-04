#include <limits.h>

#define INF 1000001 // Threshold is max 10^4, n is max 100. 10^6 + 1 is safe.

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[n][n];

    // 1. Initialize the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 2. Fill in the given edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // 3. Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 4. Find the city with the smallest number of reachable neighbors
    int minReachable = n;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }

        // If count is less than or equal to current min, update. 
        // Using <= handles the "greatest number" tie-breaker automatically
        // because we are iterating i from 0 to n-1.
        if (reachableCount <= minReachable) {
            minReachable = reachableCount;
            resultCity = i;
        }
    }

    return resultCity;
}