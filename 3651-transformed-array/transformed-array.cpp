class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int steps = abs(nums[i]) % n;
            if (nums[i] >= 0) {
                ans[i] = (steps + i) >= n ? nums[steps + i - n] : nums[steps + i];
            } else {
                ans[i] = (i - steps) < 0 ? nums[i - steps + n] : nums[i - steps];
            }
        }
        return ans;
    }
};