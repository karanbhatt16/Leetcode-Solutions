class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n,0));
        vector<vector<int>> vis(m, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int count = 0;
        while (!q.empty()) {
            count++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                if (i != 0 && vis[i - 1][j] == 0) {
                    vis[i - 1][j] = 1;
                    q.push({i - 1, j});
                    ans[i - 1][j] = count;
                }
                if (i != m - 1 && vis[i + 1][j] == 0) {
                    vis[i + 1][j] = 1;
                    q.push({i + 1, j});
                    ans[i + 1][j] = count;
                }
                if (j != 0 && vis[i][j - 1] == 0) {
                    vis[i][j - 1] = 1;
                    q.push({i, j - 1});
                    ans[i][j - 1] = count;
                }
                if (j != n - 1 && vis[i][j + 1] == 0) {
                    vis[i][j + 1] = 1;
                    q.push({i, j + 1});
                    ans[i][j + 1] = count;
                }
            }
        }
        return ans;
    }
};