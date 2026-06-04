class Solution {
public:
    // Step 1: DFS on original graph, push to stack by finish time
    void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs1(neighbor, adj, visited, st);
        }
        st.push(node);
    }

    // Step 2: DFS on transposed graph
    void dfs2(int node, vector<vector<int>> &radj, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : radj[node]) {
            if (!visited[neighbor])
                dfs2(neighbor, radj, visited);
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>> adj(V), radj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);   // original graph
            radj[e[1]].push_back(e[0]);  // transposed graph
        }

        // Step 1: Fill stack by finish order
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs1(i, adj, visited, st);

        // Step 2: Process nodes in reverse finish order on transposed graph
        fill(visited.begin(), visited.end(), false);
        int scc = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!visited[node]) {
                dfs2(node, radj, visited);
                scc++;
            }
        }

        return scc;
    }
};