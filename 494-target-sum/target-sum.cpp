class Solution {
private:
    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {

        if (i == -1) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }

        if (target < 0) {
            if (dp[i][target + 2001] != -1) {
                return dp[i][target + 2001];
            }
        } else {
            if (dp[i][target] != -1) {
                return dp[i][target];
            }
        }

        int positive = solve(nums, target + nums[i], i - 1, dp);
        int negative = solve(nums, target - nums[i], i - 1, dp);

        if (target < 0) {
            dp[i][target + 2001] = positive + negative;
        } else {
            dp[i][target] = positive + negative;
        }
        return positive + negative;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (1e5, -1));
        return solve(nums, target, n - 1, dp);
    }
};