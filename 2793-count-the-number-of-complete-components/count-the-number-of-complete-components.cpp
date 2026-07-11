class Solution {
private:
    int dfs(vector<vector<int>>& adjList, vector<int>& vis, int node) {
        vis[node] = 1;
        int ans = 0;
        for (auto x : adjList[node]) {
            if (!vis[x]) {
                ans += dfs(adjList, vis, x);
            }
        }
        return ans + adjList[node].size();
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int ans = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int edge = dfs(adjList, vis, i);
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (vis[j] == 1) count++;
                }
                if ((count - prev) * (count - prev - 1) == edge) {
                    ans++;
                }
                prev = count;
            }
        }
        return ans;
    }
};