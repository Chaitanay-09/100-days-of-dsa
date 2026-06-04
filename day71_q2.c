int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int *minDist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    
    // Initialize all distances to infinity
    for (int i = 0; i < n; i++)
        minDist[i] = INT_MAX;
    
    minDist[0] = 0;  // Start from point 0
    int totalCost = 0;
    
    for (int iter = 0; iter < n; iter++) {
        // Pick the unvisited node with minimum distance
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || minDist[i] < minDist[u]))
                u = i;
        }
        
        visited[u] = 1;
        totalCost += minDist[u];
        
        // Update distances of neighbors
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);
                if (dist < minDist[v])
                    minDist[v] = dist;
            }
        }
    }
    
    free(minDist);
    free(visited);
    return totalCost;
}