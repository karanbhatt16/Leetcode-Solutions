class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[0][i] = i;
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int a = 1 + dp[i - 1][j];
                    int b = 1 + dp[i][j - 1];
                    dp[i][j] = min(a, b);
                }
            }
        }

        return dp[n][n] / 2;
    }
};