class Solution {
private:
    int solve(vector<int>& prefix, int k, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        int minCost = INT_MAX;
        for (int idx = i; idx < j; idx += k - 1) {
            int cost = solve(prefix, k, i, idx, dp) + solve(prefix, k, idx + 1, j, dp);
            minCost = min(minCost, cost);
        }
        if ((j - i) % (k - 1) == 0) minCost += prefix[j + 1] - prefix[i];
        return dp[i][j] = minCost;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<int> prefix(n + 1, 0);
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        return solve(prefix, k, 0, n - 1, dp);
    }
};