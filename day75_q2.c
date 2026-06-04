#include <stdbool.h>
#include <stdlib.h>

// Helper function: DFS coloring
bool dfs(int** graph, int graphSize, int* graphColSize, int node, int* colors, int color) {
    colors[node] = color;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        if (colors[neighbor] == -1) {
            // Assign opposite color to neighbor
            if (!dfs(graph, graphSize, graphColSize, neighbor, colors, 1 - color)) {
                return false;
            }
        } else if (colors[neighbor] == color) {
            // Neighbor has same color → not bipartite
            return false;
        }
    }
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* colors = (int*)malloc(sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) {
        colors[i] = -1; // -1 means uncolored
    }

    for (int i = 0; i < graphSize; i++) {
        if (colors[i] == -1) {
            if (!dfs(graph, graphSize, graphColSize, i, colors, 0)) {
                free(colors);
                return false;
            }
        }
    }

    free(colors);
    return true;
}
