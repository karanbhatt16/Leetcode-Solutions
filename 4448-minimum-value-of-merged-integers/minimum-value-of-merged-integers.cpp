class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i+=2) {
            int val = nums[i + 1];
            int x = 1;
            while (val != 0) {
                x = x * 10;
                val /= 10;
            }
            mn = min(mn, nums[i] * x + nums[i + 1]);
        }
        return mn;
    }
};