class Solution {
    int timer = 0;
    
    void dfs(int u, int parent, vector<int> adj[], 
             vector<int>& disc, vector<int>& low, vector<bool>& ap) {
        disc[u] = low[u] = ++timer;
        int children = 0;
        
        for (int v : adj[u]) {
            if (disc[v] == -1) {  // not visited
                children++;
                dfs(v, u, adj, disc, low, ap);
                
                low[u] = min(low[u], low[v]);
                
                // Root with 2+ children
                if (parent == -1 && children > 1)
                    ap[u] = true;
                
                // Non-root: subtree can't bypass u
                if (parent != -1 && low[v] >= disc[u])
                    ap[u] = true;
                    
            } else if (v != parent) {  // back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, 0);
        vector<bool> ap(V, false);
        
        for (int i = 0; i < V; i++)
            if (disc[i] == -1)
                dfs(i, -1, adj, disc, low, ap);
        
        vector<int> result;
        for (int i = 0; i < V; i++)
            if (ap[i]) result.push_back(i);
        
        // Return {-1} if no articulation points found
        return result.empty() ? vector<int>{-1} : result;
    }
};