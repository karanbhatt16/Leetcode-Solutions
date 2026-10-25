class Solution {
private:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                dfs(grid, nx, ny);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                dfs(grid, i, 0);
            }
            if (grid[i][m - 1] == 0) {
                dfs(grid, i, m - 1);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) {
                dfs(grid, 0, j);
            }
            if (grid[n - 1][j] == 0) {
                dfs(grid, n - 1, j);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};