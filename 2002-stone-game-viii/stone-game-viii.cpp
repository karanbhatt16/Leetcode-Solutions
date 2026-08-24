class Solution {
private:
    int solve(vector<int>& stones, int i, vector<int>& dp) {
        if (i == stones.size() - 1) {
            return stones[i];
        }
        if (dp[i] != INT_MIN) return dp[i];
        int a, b;
        a = solve(stones, i + 1, dp);
        b = stones[i] - solve(stones, i + 1, dp);
        return dp[i] = max(a, b);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }
        vector<int> dp(n, INT_MIN);
        return solve(stones, 1, dp);
    }
};