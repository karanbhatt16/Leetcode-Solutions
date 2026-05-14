class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] != 1) {
                if (i == n - 1 && nums[i] == nums[i - 1] && nums[i] == n - 1) return true;
                return false;
            }
        }
        return false;
    }
};