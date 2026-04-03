class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        queue<int> q;
        bool ans = true;

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                q.push(i);
                vis[i] = 0;
                while(!q.empty()) {
                    int size = q.size();
                    for (int j = 0; j < size; j++) {
                        int node = q.front();
                        q.pop();
                        for (int x : graph[node]) {
                            if (vis[x] == -1) {
                                vis[x] = !vis[node];
                                q.push(x);
                            }
                            if (vis[x] == vis[node]) {
                                ans = false;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};