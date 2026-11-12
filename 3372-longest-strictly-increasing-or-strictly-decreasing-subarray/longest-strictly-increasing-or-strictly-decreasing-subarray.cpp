class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prev = 0;
        int prev2 = 51;
        int count = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > prev) {
                prev = nums[i];
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
                prev = nums[i];
            }


            if (nums[i] < prev2) {
                prev2 = nums[i];
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
                prev2 = nums[i];
            }
        }
        ans = max({ans, count, cnt});
        return ans;
    }
};