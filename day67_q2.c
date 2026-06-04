#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int **adj;
int *adjSize;
int *visited;   // 0 = unvisited, 1 = visiting, 2 = visited
int *result;
int index;
int hasCycle = 0;

// DFS function
void dfs(int v) {
    if (hasCycle) return;

    visited[v] = 1; // visiting

    for (int i = 0; i < adjSize[v]; i++) {
        int nei = adj[v][i];

        if (visited[nei] == 0) {
            dfs(nei);
        } else if (visited[nei] == 1) {
            hasCycle = 1; // cycle detected
            return;
        }
    }

    visited[v] = 2; // visited
    result[index--] = v; // store in reverse order
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    // Allocate adjacency list
    adj = (int**)malloc(numCourses * sizeof(int*));
    adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // max possible
    }

    // Build graph: b -> a
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
    }

    visited = (int*)calloc(numCourses, sizeof(int));
    result = (int*)malloc(numCourses * sizeof(int));
    index = numCourses - 1;

    // DFS for all nodes
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    // If cycle → return empty
    if (hasCycle) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numCourses;
    return result;
}