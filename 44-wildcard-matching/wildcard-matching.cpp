class Solution {
private:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 || j < 0) {
            if (i < 0 && j < 0) {
                return true;
            }
            if (i < 0) {
                while (j >= 0 && p[j] == '*') {
                    j--;
                }
                if (j < 0) {
                    return true;
                }
            }
            return false;
        }

        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }

        if (p[j] == '?' || s[i] == p[j]) {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        } else if (p[j] == '*'){
            int k = 0;
            while (k <= i + 1 && !solve(s, p, i - k, j - 1, dp)) {
                k++;
            }
            if (k <= i + 1) {
                return dp[i][j] = true;
            }
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(s, p, n - 1, m - 1, dp);
    }
};