class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int n = s.length();
        vector<int> vis(n, 0);
        vis[0] = 1;
        int farthest = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                if (node == n - 1){
                    return true;
                }
                int start = max(node + minJump, farthest + 1);
                int end = min(node + maxJump, n - 1);
                for (int j = start; j <= end; j++) {
                    if (!vis[j] && s[j] == '0') {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
                farthest = end;
            }
        }
        return false;
    }
};