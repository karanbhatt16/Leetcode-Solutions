class Solution {
private:
    int n, m;
    bool solve(vector<vector<char>>& grid, int x, int y, int count, vector<vector<vector<int>>>& dp) {
        if (x >= n || y >= m) {
            return false;
        }
        if (grid[x][y] == '(') {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            return false;
        }
        if (dp[x][y][count] != -1) {
            return dp[x][y][count];
        }
        if (x == n - 1 && y == m - 1) {
            return count == 0;
        }

        bool a = solve(grid, x + 1, y, count, dp);
        bool b = solve(grid, x, y + 1, count, dp);
        return dp[x][y][count] = a | b;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (n + m, -1)));
        return solve(grid, 0, 0, 0, dp);
    }
};