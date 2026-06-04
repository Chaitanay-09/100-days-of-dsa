int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // Initialize distances with infinity
    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Relax edges k+1 times (k stops = k+1 edges)
    for (int i = 0; i <= k; i++) {
        // IMPORTANT: use a temp copy to avoid using updated values in same iteration
        int* temp = (int*)malloc(n * sizeof(int));
        memcpy(temp, dist, n * sizeof(int));

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        free(dist);
        dist = temp;
    }

    int result = (dist[dst] == INT_MAX) ? -1 : dist[dst];
    free(dist);
    return result;
}