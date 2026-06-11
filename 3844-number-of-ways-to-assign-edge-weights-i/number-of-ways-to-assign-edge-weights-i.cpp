class Solution {
private:
    int MOD = 1e9 + 7;
    int heightOfTree(unordered_map<int, vector<int>>& mp, int n) {
        queue<int> q;
        q.push(1);

        vector<int> vis(n + 1, 0);

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int node = q.front();
                q.pop();
                vis[node - 1] = 1;

                for (int i = 0; i < mp[node].size(); i++) {
                    if (!vis[mp[node][i] - 1]) {
                        q.push(mp[node][i]);
                    }
                }
            }
            count++;
        }
        return count - 1;
    }

    long long solve(int n, int parity, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1 & parity;
        }
        if (dp[n][parity] != -1) {
            return dp[n][parity];
        }
        int a = solve(n - 1, parity ^ 1, dp);
        int b = solve(n - 1, parity, dp);

        return dp[n][parity] = (a + b) % MOD;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;

        int n = edges.size();

        for (int i = 0; i < n; i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        int height = heightOfTree(mp, n);
        
        vector<vector<int>> dp(height + 1, vector<int> (2, -1));

        return solve(height, 0, dp);
    }
};