class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minimum = 51;
        int second_minimum = 51;
        for (int i = 1; i < nums.size(); i++) {
            if (minimum >= nums[i]) {
                second_minimum = minimum;
                minimum = nums[i];
                continue;
            }
            if (second_minimum > nums[i]) {
                second_minimum = nums[i];
            }
        }
        return nums[0] + minimum + second_minimum;
    }
};