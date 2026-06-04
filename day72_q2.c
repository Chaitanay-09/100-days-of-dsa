class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        
        // Base case: single city
        if (n == 1) return 0;
        
        int full = (1 << n) - 1;
        
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        dp[1][0] = 0;
        
        for (int mask = 1; mask <= full; mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;
                if (dp[mask][u] == INT_MAX) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;
                    
                    int newMask = mask | (1 << v);
                    dp[newMask][v] = min(dp[newMask][v], 
                                        dp[mask][u] + cost[u][v]);
                }
            }
        }
        
        int ans = INT_MAX;
        for (int u = 1; u < n; u++) {
            if (dp[full][u] != INT_MAX)
                ans = min(ans, dp[full][u] + cost[u][0]);
        }
        
        return ans;
    }
};