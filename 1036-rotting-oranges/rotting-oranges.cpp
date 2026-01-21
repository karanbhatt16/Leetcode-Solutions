class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        int count = -1;
        while (!q.empty()) {
            int size = q.size();
            count++;
            for (int k = 0; k < size; k++) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                if (i != 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == 0) {
                    visited[i - 1][j] = 1;
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                } 
                if (i != m - 1 && grid[i + 1][j] == 1 && visited[i + 1][j] == 0) {
                    visited[i + 1][j] = 1;
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if (j != 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == 0) {
                    visited[i][j - 1] = 1;
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                } 
                if (j != n - 1 && grid[i][j + 1] == 1 && visited[i][j + 1] == 0) {
                    visited[i][j + 1] = 1;
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count == -1 ? 0 : count;
    }
};