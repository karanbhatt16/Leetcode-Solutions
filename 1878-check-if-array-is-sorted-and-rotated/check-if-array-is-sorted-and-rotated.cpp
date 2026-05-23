class Solution {
public:
    bool check(vector<int>& nums) {
        int mini = nums[0];
        int i;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                break;
            }
        }
        for (int k = i; k < nums.size(); k++) {
            if (i != k && nums[k] < nums[k - 1]) return false;
            if (mini < nums[k]) {
                return false;
            }
        }
        return true;
    }
};