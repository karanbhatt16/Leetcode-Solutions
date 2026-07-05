class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> digitRange(n, 0);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int mini = 9;
            int mx = 0;
            while (num != 0) {
                int rem = num % 10;
                mini = min(mini, rem);
                mx = max(mx, rem);
                num /= 10;
            }
            ans = max(ans, mx - mini);
            digitRange[i] = mx - mini;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (digitRange[i] == ans) {
                res += nums[i];
            }
        }
        return res;
    }
};