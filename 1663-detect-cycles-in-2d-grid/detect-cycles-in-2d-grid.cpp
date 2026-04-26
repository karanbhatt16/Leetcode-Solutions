class Solution {
private:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int previ, int prevj) {
        vis[i][j] = 1;
        vector<int> row = {1, 0, -1, 0};
        vector<int> col = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int rowidx = i + row[k];
            int colidx = j + col[k];
            if (rowidx >= 0 && rowidx < grid.size() && colidx >= 0 && colidx < grid[0].size() && grid[rowidx][colidx] == grid[i][j] && (rowidx != previ || colidx != prevj)) {
                if (!vis[rowidx][colidx]) {
                    if (dfs(grid, vis, rowidx, colidx, i, j) == true) {
                        return true;
                    }
                } else {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, vis, i, j, i, j) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};