class Solution {
private:
    int solve(vector<int>& nums, int i, int j, bool x, vector<vector<vector<int>>>& dp) {
        if (i == j) {
            return nums[j];
        }
        if (dp[i][j][x] != -1) {
            return dp[i][j][x];
        }
        if (x) {
            int a = nums[i] + solve(nums, i + 1, j, !x, dp);
            int b = nums[j] + solve(nums, i, j - 1, !x, dp);
            return dp[i][j][x] = max(a, b);
        } else {
            int a = solve(nums, i + 1, j, !x, dp);
            int b = solve(nums, i, j - 1, !x, dp);
            return dp[i][j][x] = min(a, b);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
        if (2 * solve(nums, 0, n - 1, true, dp) >= sum) {
            return true;
        }
        return false;
    }
};