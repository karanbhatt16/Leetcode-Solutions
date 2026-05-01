class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += (i * nums[i]);
            sum += nums[i];
        }
        int res = ans;
        for (int i = n - 1; i >= 0; i--) {
            ans -= (n * nums[i]);
            ans += sum;
            res = max(res, ans);
        }
        return res;
    }
};