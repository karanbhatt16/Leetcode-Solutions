class Solution {
private:
    bool solve(vector<int>& nums, vector<vector<int>>& dp, int i, int target) {
        if (target == 0) return true;
        if (i == 0) return nums[i] == target;
        
        if (dp[i][target] != -1) return dp[i][target] != 0;

        bool not_take = solve(nums, dp, i - 1, target);
        bool take = false;
        if (nums[i] <= target) {
            take = solve(nums, dp, i - 1, target - nums[i]);
        }
        return dp[i][target] = take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            target += nums[i];
        }
        vector<vector<int>> dp(n, vector<int> (target, -1));
        if (target % 2 != 0) return false;
        return solve (nums, dp, n - 1, target / 2);
    }
};