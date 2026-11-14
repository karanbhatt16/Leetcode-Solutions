class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        for (int len = l; len <= r; len++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (i == len - 1 && sum > 0) ans = min(ans, sum);
                if (i >= len) {
                    sum -= nums[i - len];
                } else {
                    continue;
                }
                if (sum > 0) {
                    ans = min(sum, ans);
                }
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};