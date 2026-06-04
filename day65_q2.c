#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<int> adj[V];

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Visited array
        vector<int> visited(V, 0);

        // Step 3: Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};