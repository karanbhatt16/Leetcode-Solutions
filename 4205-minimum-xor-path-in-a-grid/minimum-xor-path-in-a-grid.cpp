class Solution {
private:
    int n, m;
    bool solve(vector<vector<int>>& grid, int x, int y, int val, vector<vector<vector<int>>>& dp) {
        if (x == n - 1 && y == m - 1) {
            val = val ^ grid[x][y];
            return (val == 0);
        }
        if (x >= n || y >= m) {
            return false;
        }
        if (dp[x][y][val] != -1) {
            return dp[x][y][val];
        }
        bool a = solve(grid, x + 1, y, val ^ grid[x][y], dp);
        bool b = solve(grid, x, y + 1, val ^ grid[x][y], dp);
        return dp[x][y][val] = a | b;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (1024, -1)));
        for (int i = 0; i <= 1023; i++) {
            if (solve(grid, 0, 0, i, dp)) return i;
        }
        return 0;
    }
};