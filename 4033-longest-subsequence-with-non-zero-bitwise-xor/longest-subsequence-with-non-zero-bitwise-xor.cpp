class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            }
            xorr = xorr ^ nums[i];
        }
        if (count == n) return 0;
        if (xorr == 0) {
            if (count > n - 2) {
                return n - count - 1;
            }
            return n - 1;
        }
        return n;
    }
};