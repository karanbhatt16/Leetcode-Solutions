class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int m, int n, int& ones) {
        visited[i][j] = 1;
        ones++;
        if (i != m - 1 && grid[i + 1][j] == 1 && visited[i + 1][j] != 1){
            dfs(grid, visited, i + 1, j, m, n, ones);
        }
        if (i != 0 && grid[i - 1][j] == 1 && visited[i - 1][j] != 1){
            dfs(grid, visited, i - 1, j, m, n, ones);
        }
        if (j != n - 1 && grid[i][j + 1] == 1 && visited[i][j + 1] != 1){
            dfs(grid, visited, i, j + 1, m, n, ones);
        }
        if (j != 0 && grid[i][j - 1] == 1 && visited[i][j - 1] != 1){
            dfs(grid, visited, i, j - 1, m, n, ones);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int total_ones = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    total_ones++;
                }
            }
        }
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ones = 0;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && visited[i][0] != 1) {
                dfs(grid, visited, i, 0, m, n, ones);
            }
            if (grid[i][n - 1] == 1 && visited[i][n - 1] != 1) {
                dfs(grid, visited, i, n - 1, m, n, ones);
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && visited[0][j] != 1) {
                dfs(grid, visited, 0, j, m, n, ones);
            }
            if (grid[m - 1][j] == 1 && visited[m - 1][j] != 1) {
                dfs(grid, visited, m - 1, j, m, n, ones);
            }
        }
        return total_ones - ones;
    }
};