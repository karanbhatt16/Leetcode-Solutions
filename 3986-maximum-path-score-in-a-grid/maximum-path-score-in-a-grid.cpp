class Solution {
private:
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k + 1, -1)));
        int c = 0;
        int x = 0;
        for (int i = 0; i < n; i++) {
            c += !!grid[i][0];
            x += grid[i][0];
            if (c <= k) {
                dp[i][0][c] = x;
            }
        }
        c = 0;
        x = 0;
        for (int j = 0; j < m; j++) {
            c += !!grid[0][j];
            x += grid[0][j];
            if (c <= k) {
                dp[0][j][c] = x;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int c = 0; c <= k; c++) {
                    int up = 0;
                    int left = 0;
                    if (i > 0 && j > 0 && dp[i - 1][j][c] == -1 && dp[i][j - 1][c] == -1) continue;
                    if (i > 0 && dp[i - 1][j][c] != -1) {
                        up = dp[i - 1][j][c];
                    }
                    if (j > 0 && dp[i][j - 1][c] != -1) {
                        left = dp[i][j - 1][c];
                    }
                    int cost = c + !!grid[i][j];
                    if (cost <= k && cost >= 0) {
                        dp[i][j][cost] = max(left, up) + grid[i][j];
                    }
                }
            }
        }
        int score = -1;
        for (int i = 0; i <= k; i++) {
            score = max(score, dp[n - 1][m - 1][i]);
        }
        return score;
    }
};