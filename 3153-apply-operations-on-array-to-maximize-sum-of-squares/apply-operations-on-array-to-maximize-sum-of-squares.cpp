class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> b(30, 0);
        long long ans = 0;
        int n = nums.size();
        long long MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if (nums[i] & (1 << j)) b[j]++;
            }
        }

        while (k-- > 0) {
            long long x = 0;
            for (int i = 0; i < 30; i++) {
                if (b[i] > 0) {
                    x |= 1LL << i;
                    b[i]--;
                }
            }
            ans = (ans + x * x) % MOD;
        }
        return (int) ans;
    }
};