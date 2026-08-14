class Solution {
private:
    int row, col;
    int solve(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        if (i >= row) {
            return 0;
        }
        if (j1 >= j2) {
            return 0;
        }
        if (j1 < 0 || j2 >= col) {
            return 0;
        }

        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int case1 = solve(grid, i + 1, j1 - 1, j2 - 1, dp);
        int case4 = solve(grid, i + 1, j1 - 1, j2, dp);
        int case6 = solve(grid, i + 1, j1 - 1, j2 + 1, dp);
        int case7 = solve(grid, i + 1, j1, j2 - 1, dp);
        int case2 = solve(grid, i + 1, j1, j2, dp);
        int case5 = solve(grid, i + 1, j1, j2 + 1, dp);
        int case8 = solve(grid, i + 1, j1 + 1, j2 - 1, dp);
        int case9 = solve(grid, i + 1, j1 + 1, j2, dp);
        int case3 = solve(grid, i + 1, j1 + 1, j2 + 1, dp);

        return dp[i][j1][j2] = max({case1, case2, case3, case4, case5, case6, case7, case8, case9}) + grid[i][j1] + grid[i][j2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return solve(grid, 0, 0, col - 1, dp);
    }
};