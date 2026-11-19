class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // case 1
        int high = nums[n - 1] - nums[2];
        // case 2
        high = min(high, nums[n - 3] - nums[0]);
        // case 3
        high = min(high, nums[n - 2] - nums[1]);
        return high;
    }
};