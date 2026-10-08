class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (int i = 1; i < n; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
        int prev = diff[1];
        int count = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (diff[i] == prev) {
                count++;
            } else {
                if (count > 1) {
                    ans += ((count) * (count - 1)) / 2;
                }
                count = 1;
                prev = diff[i];
            }
        }
        if (count > 1) {
            ans += ((count) * (count - 1)) / 2;
        }
        return ans;
    }
};