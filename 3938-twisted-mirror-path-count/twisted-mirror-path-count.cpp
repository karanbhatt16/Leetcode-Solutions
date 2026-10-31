class Solution {
private:
    int n, m;
    int MOD = 1e9 + 7;
    long long solve(vector<vector<int>>& grid, int x, int y, int direction, vector<vector<vector<int>>>& dp) {
        if (x == n - 1 && y == m - 1) {
            return 1;
        }
        if (x >= n || y >= m) {
            return 0;
        }
        if (dp[x][y][direction] != -1) {
            return dp[x][y][direction];
        }
        long long a = 0, b = 0;
        if (grid[x][y] == 0) {
            a = solve(grid, x + 1, y, 0, dp);
            b = solve(grid, x, y + 1, 1, dp);
        } else {
            if (direction == 0) {
                a = solve(grid, x, y + 1, 1, dp);
            } else {
                b = solve(grid, x + 1, y, 0, dp);
            }
        }
        return dp[x][y][direction] = (a + b) % MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, -1)));
        return solve(grid, 0, 0, 0, dp);
    }
};