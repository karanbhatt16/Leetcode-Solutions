class Solution {
private:
    bool isSorted(vector<int>&nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int minIndex(vector<int>& nums, int& val) {
        int index = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < val) {
                val = sum;
                index = i;
            }
        }
        return index;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (!isSorted(nums)) {
            int val = INT_MAX;
            int index = minIndex(nums, val);
            nums.erase(nums.begin() + index);
            nums[index] = val;
            count++;
        }
        return count;
    }
};