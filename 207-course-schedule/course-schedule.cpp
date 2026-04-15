class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            vis[prerequisites[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto x : adj[node]) {
                vis[x]--;
                if (vis[x] == 0) q.push(x);
            }
            count++;
        }
        if (count == numCourses) return true;
        return false;
    }
};