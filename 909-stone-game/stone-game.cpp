class Solution {
private:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) {
            return nums[j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int a = nums[i] + min(solve(nums, i + 2, j, dp), solve(nums, i + 1, j - 1, dp));
        int b = nums[j] + min(solve(nums, i + 1, j - 1, dp), solve(nums, i, j - 2, dp));
        return dp[i][j] = max(a, b);
    }
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int> (n, -1));
        if (2 * solve(nums, 0, n - 1, dp) >= sum) {
            return true;
        }
        return false;
    }
};