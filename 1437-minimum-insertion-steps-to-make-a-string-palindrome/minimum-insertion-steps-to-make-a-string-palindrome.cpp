class Solution {
private:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (i == -1 || j == -1) {
            if (i == -1 && j == -1) return 0;
            if (i == -1) return j + 1;
            if (j == -1) return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
        } else {
            int a = 1 + solve(s, t, i - 1, j, dp);
            int b = 1 + solve(s, t, i, j - 1, dp);
            return dp[i][j] = min(a, b);
        }
    }
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();

        vector<vector<int>> dp(n, vector<int> (n, -1));

        return solve(s, t, n - 1, n - 1, dp) / 2;
    }
};