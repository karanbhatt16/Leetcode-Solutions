class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        for (int i = n - 2; i >= 0; i--) {
            int ans = 1e5;
            for (int k = i + 1; k <= nums[i] + i && k < n; k++) {
                int x = 1 + dp[k];
                ans = min(ans, x);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};