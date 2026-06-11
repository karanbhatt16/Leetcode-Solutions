class Solution {
private:
    int heightOfTree(unordered_map<int, vector<int>>& mp, int n) {
        queue<int> q;
        q.push(1);

        vector<int> vis(n + 1, 0);

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int node = q.front();
                q.pop();
                vis[node - 1] = 1;

                for (int i = 0; i < mp[node].size(); i++) {
                    if (!vis[mp[node][i] - 1]) {
                        q.push(mp[node][i]);
                    }
                }
            }
            count++;
        }
        return count - 1;
    }
    long long powmod(long long base, long long exp) {
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
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;

        int n = edges.size();

        for (int i = 0; i < n; i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        int height = heightOfTree(mp, n);

        return powmod(2, height - 1);
    }
};