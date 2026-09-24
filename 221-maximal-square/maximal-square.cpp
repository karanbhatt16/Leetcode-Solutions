class Solution {
private:
    int n, m;
    int solve(vector<vector<char>>& matrix, int x, int y, vector<vector<int>>& dp) {
        if (x >= n || y >= m) {
            return 0;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        if (matrix[x][y] != '1') {
            return 0;
        }
        int a = solve(matrix, x + 1, y, dp);
        int b = solve(matrix, x, y + 1, dp);
        int c = solve(matrix, x + 1, y + 1, dp);

        return dp[x][y] = 1 + min({a, b, c});
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    ans = max(ans, solve(matrix, i, j, dp));
                }
            }
        }
        return ans * ans;
    }
};