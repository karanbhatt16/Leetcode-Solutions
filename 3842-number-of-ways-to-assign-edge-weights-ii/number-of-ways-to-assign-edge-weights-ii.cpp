class Solution {
private:
    
    void dfs(int node, int parent,
         unordered_map<int, vector<int>>& adj,
         vector<int>& depth,
         vector<vector<int>>& up) {

        up[node][0] = parent;

        for (int j = 1; j < 20; j++) {
            up[node][j] = up[ up[node][j - 1] ][j - 1];
        }

        for (int child : adj[node]) {
            if (child == parent) continue;

            depth[child] = depth[node] + 1;
            dfs(child, node, adj, depth, up);
        }
    }
    
    long long powmod(long long base, long long exp) {
        if (exp < 0) return 0;
        long long result = 1;
        const long long MOD = 1e9 + 7;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }
    int lca(int a, int b,
        vector<int>& depth,
        vector<vector<int>>& up) {

        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        // Lift a to same depth as b
        for (int j = 19; j >= 0; j--) {
            if (diff & (1 << j))
                a = up[a][j];
        }

        if (a == b)
            return a;

        // Lift both together
        for (int j = 19; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        int n = edges.size();

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n + 2, 0);

        int LOG = 20;
        vector<vector<int>> up(n + 2, vector<int>(LOG, 0));

        dfs(1, 0, adj, depth, up);

        vector<int> ans;

        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            int distance = depth[u] + depth[v] - 2 * depth[lca(u, v, depth, up)];
            ans.push_back(powmod(2, distance - 1));
        }

        return ans;
    }
};