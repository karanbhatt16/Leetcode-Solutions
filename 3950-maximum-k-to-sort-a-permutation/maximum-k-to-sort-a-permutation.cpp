class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != sorted[i]) {
                ans &= (nums[i] & sorted[i]);
            }
        }
        if (ans == -1) {
            return 0;
        }
        return ans;
    }
};