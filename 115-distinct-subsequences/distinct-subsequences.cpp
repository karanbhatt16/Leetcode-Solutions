class Solution {
private:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {

        if (j < 1) {
            return 1;
        }
        if (i < 1) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int pick = 0;
        int notPick = 0;

        if (s[i - 1] == t[j - 1]) {
            pick = solve(s, t, i - 1, j - 1, dp);
        }

        notPick = solve(s, t, i - 1, j, dp);

        return dp[i][j] = pick + notPick;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(s, t, n, m, dp);
    }
};