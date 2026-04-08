class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, vector<int>& pathvis, vector<int>& check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for (int x : graph[node]) {
            if (!vis[x]) {
                if(dfs(graph, vis, x, pathvis, check) == true) return true;
            } else if (pathvis[x]){
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);
        vector<int> safe;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(graph, vis, i, pathvis, check);
            }
        }
        for (int i = 0; i <n; i++) {
            if (check[i] == 1) {
                safe.push_back(i);
            }
        }
        return safe;
    }
};