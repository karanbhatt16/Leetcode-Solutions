class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32, 0);
        int n = nums.size();
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if ((nums[i] & (1 << j)) != 0) bits[j]++; 
            }
        }

        long long ans = 0;
        while (k--) {
            long long val = 0;
            for (int i = 0; i < 32; i++) {
                if (bits[i] > 0) {
                    bits[i]--;
                    val += (1 << i);
                }
            }
            ans = (ans + val * val) % MOD;
            cout << val << " ";
        }
        return (int)ans;
    }
};