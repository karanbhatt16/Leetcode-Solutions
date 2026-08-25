class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = 1;
        for (int i = 0; i < n; i++) {
            if (k * x < nums[i]) {
                return k * x;
            }
            if (k * x == nums[i]) {
                x++;
            }
        }
        return k * x;
    }
};