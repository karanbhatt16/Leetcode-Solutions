class Solution {
private:
    int n;
    bool solve(string& s, int i, int count, vector<vector<int>>& dp) {
        if (i >= n) {
            return count == 0;
        }
        if (count < 0) {
            return false;
        }
        if (dp[i][count] != -1) {
            return dp[i][count];
        }
        bool a, b, c;
        a = b = c = false;
        if (s[i] == '(') {
            a = solve(s, i + 1, count + 1, dp);
        } else if (s[i] == ')') {
            a = solve(s, i + 1, count - 1, dp);
        } else {
            a = solve(s, i + 1, count + 1, dp);
            b = solve(s, i + 1, count, dp);
            c = solve(s, i + 1, count - 1, dp);
        }
        return dp[i][count] = a | b | c;
    }
public:
    bool checkValidString(string s) {
        n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(s, 0, 0, dp);
    }
};