class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1) {
                    return count;
                }
                vis[idx] = 1;
                int next = idx + 1;
                int prev = idx - 1;
                if (next < n && !vis[next]) {
                    q.push(next);
                }
                if (prev >= 0 && !vis[prev]) {
                    q.push(prev);
                }
                for (auto x : mp[arr[idx]]) {
                    if (!vis[x]) {
                        q.push(x);
                    }
                }
                mp[arr[idx]].clear();
            }
            count++;
        }
        return -1;
    }
};