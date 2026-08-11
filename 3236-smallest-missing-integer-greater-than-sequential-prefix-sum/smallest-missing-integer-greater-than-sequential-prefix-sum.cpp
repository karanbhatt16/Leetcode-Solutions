class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];
        int mx = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                count++;
                prefixSum += nums[i];
            } else {
                mx = max(mx, prefixSum);
                break;
            }
            if (i == n - 1) {
                mx = max(mx, prefixSum);
            }
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (mx == nums[i]) {
                mx = mx + 1;
            }
        }
        return mx;
    }
};