class Solution {
private:
    bool solve(unordered_map<int, int>& mp, vector<int>& stones, int i, int k, vector<vector<int>>& dp) {
        if (i == stones.size() - 1) {
            return true;
        }
        if (i > stones.size()) {
            return false;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        int jump1 = k - 1;
        int jump2 = k;
        int jump3 = k + 1;
        bool ans = false;
        if (jump1 > 0) {
            if (mp[stones[i] + jump1]) {
                ans = ans | solve(mp, stones, mp[stones[i] + jump1], jump1, dp);
            }
        }
        if (jump2 > 0) {
            if (mp[stones[i] + jump2]) {
                ans = ans | solve(mp, stones, mp[stones[i] + jump2], jump2, dp);
            }
        }
        if (jump3 > 0) {
            if (mp[stones[i] + jump3]) {
                ans = ans | solve(mp, stones, mp[stones[i] + jump3], jump3, dp);
            }
        }
        return dp[i][k] = ans;
    }
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mp;

        int n = stones.size();
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(mp, stones, 0, 0, dp);
    }
};