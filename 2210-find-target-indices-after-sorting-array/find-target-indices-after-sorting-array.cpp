class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int small = 0, large = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < target) {
                small++;
            } else if (nums[i] > target) {
                large++;
            }
        }

        for (int i = small; i < n - large; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};