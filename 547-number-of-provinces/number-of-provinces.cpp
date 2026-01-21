class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& v) {
        v[node] = 1;
        for (auto it : adj[node]) {
            if (!v[it]) {
                dfs(it, adj, v);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<vector<int>> adj(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isConnected[i][j] && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(size);
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};