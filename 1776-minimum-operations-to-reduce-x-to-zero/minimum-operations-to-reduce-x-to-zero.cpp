class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        int target = sum - x;
        int j = 0;
        int length = 0;
        if (target < 0) return -1;
        if (target == 0) return n;
        for (int i = 0; i < n; i++) {
            target -= nums[i];
            while (target < 0) {
                target += nums[j];
                j++;
            }
            if (target == 0) {
                length = max(length, i - j + 1);
            }
        }
        if (length == 0) return -1;
        return n - length;
    }
};