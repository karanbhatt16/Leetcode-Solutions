class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int& cnt, int empty) {
        if (grid[i][j] == 2 && empty == 0) {
            cnt++;
            return;
        }
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> r = {1, 0, -1, 0};
        vector<int> c = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int row = i + r[k];
            int col = j + c[k];
            if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] != -1) {
                dfs(grid, vis, row, col, cnt, empty - 1);
            }
        }
        vis[i][j] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt = 0;
        int empty = 0;
        int starti = 0;
        int startj = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) empty++;
                if (grid[i][j] == 1) {
                    starti = i;
                    startj = j;
                }
            }
        }
        dfs(grid, vis, starti, startj, cnt, empty + 1);
        return cnt;
    }
};