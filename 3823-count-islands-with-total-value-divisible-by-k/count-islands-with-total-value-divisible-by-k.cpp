class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;
    long long dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis) {
        vis[x][y] = 1;
        long long sum = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != 0 && !vis[nx][ny]) {
                sum += dfs(grid, nx, ny, vis);
            }
        }
        return sum + grid[x][y];
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long sum = dfs(grid, i, j, vis);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};