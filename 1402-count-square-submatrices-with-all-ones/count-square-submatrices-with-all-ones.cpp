class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (n + 1, 0)));

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j][1] = 1;
                    count++;
                }
            }
        }

        for (int k = 2; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= m - k; j++) {
                    if (matrix[i][j] == 1 && i + k <= n && j + k <= m && dp[i + 1][j + 1][k - 1] && dp[i + 1][j][k - 1] && dp[i][j + 1][k - 1]) {
                        dp[i][j][k] = 1;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};