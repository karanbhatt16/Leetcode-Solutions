class Solution {
private:
    void fill(vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 2;

        for (auto x : adj[node]) {
            if (!vis[x]) {
                fill(adj, vis, x);
            }
        }
    }
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 1;

        for (auto x : adj[node]) {
            if (!vis[x]) {
                if (dfs(adj, vis, x)) {
                    return true;
                }
            } else if (vis[x] == 2) {
                return true;
            }
        }
        return false;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(n, 0);

        fill(adj, vis, k);

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, i)) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            vector<int> ans(n, 0);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        } else {
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (vis[i] != 2) {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    }
};