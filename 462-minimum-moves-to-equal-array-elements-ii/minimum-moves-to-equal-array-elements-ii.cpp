class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        long long mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long left = 1LL * nums[i] * (i + 1) - prefix[i];
            long long right = prefix[n - 1] - 1LL * nums[i] * (n - i) - prefix[i] + nums[i];
            mn = min(mn, right + left);
        }
        return mn;
    }
};