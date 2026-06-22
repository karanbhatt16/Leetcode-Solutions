class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n + 1);
        vector<bool> visited(n + 1, false);

        for (auto road : roads) {
            int a, b, w;
            a = road[0];
            b = road[1];
            w = road[2];
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        queue<int> q;
        visited[1] = true;
        q.push(1);
        int mini = 1e9;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (auto u : adj[s]) {
                mini = min(u.second, mini);
                if (visited[u.first]) continue;
                visited[u.first] = true;
                q.push(u.first);
            }
        }
        return mini;
    }
};