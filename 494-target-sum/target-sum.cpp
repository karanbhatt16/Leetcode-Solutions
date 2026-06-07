class Solution {
private:
    int T;
    int totalSum;
    int solve(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {

        if (i == -1) {
            if (totalSum - 2 * sum == T) {
                return 1;
            }
            return 0;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int pick = solve(nums, sum + nums[i], i - 1, dp);
        int notpick = solve(nums, sum, i - 1, dp);

        return dp[i][sum] = pick + notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        T = target;
        totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int> (totalSum + 1, -1));
        return solve(nums, 0, n - 1, dp);
    }
};