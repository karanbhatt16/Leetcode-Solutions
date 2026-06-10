class Solution {
private:
    int solve(string text1, string text2, int idx1, int idx2, vector<vector<int>>& dp) {

        if (idx1 < 0 || idx2 < 0) {
            return 0;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        if (text1[idx1] == text2[idx2]) {
            return 1 + solve(text1, text2, idx1 - 1, idx2 - 1, dp);
        }

        int i1 = idx1, i2 = idx2;

        while (i1 >= 0 && text1[i1] == text1[idx1]) {
            i1--;
        }
        while (i2 >= 0 && text2[i2] == text2[idx2]) {
            i2--;
        }

        int left = solve(text1, text2, i1, idx2, dp);
        int right = solve(text1, text2, idx1, i2, dp);

        return dp[idx1][idx2] = max(left, right);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return solve(text1, text2, text1.length() - 1, text2.length() - 1, dp);
    }
};