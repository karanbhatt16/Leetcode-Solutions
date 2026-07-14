class Solution {
private:
    static const int MOD = 1e9 + 7;
    int dp[201][201][201];

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int solve(vector<int>& nums, int i, int x, int y) {
        if (i == nums.size()) {
            return (x != 0 && y != 0 && x == y);
        }

        if (dp[i][x][y] != -1)
            return dp[i][x][y];

        long long ans = 0;

        ans += solve(nums, i + 1, x, y);

        int gx = (x == 0 ? nums[i] : gcd(x, nums[i]));
        ans += solve(nums, i + 1, gx, y);

        int gy = (y == 0 ? nums[i] : gcd(y, nums[i]));
        ans += solve(nums, i + 1, x, gy);

        return dp[i][x][y] = ans % MOD;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};