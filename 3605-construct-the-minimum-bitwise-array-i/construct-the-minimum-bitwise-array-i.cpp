class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            for (int j = nums[i] / 2; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};