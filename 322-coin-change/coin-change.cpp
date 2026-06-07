class Solution {
private:
    long long solve(vector<int>& coins, int amount, vector<long long>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int n = coins.size();
        long long ans = pow(2,31);

        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount) {
                long long count = solve(coins, amount - coins[i], dp) + 1;
                ans = min(ans, count);
            }
        }

        return dp[amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, -1);
        long long res = solve(coins, amount, dp);
        if (res > INT_MAX) {
            return -1;
        }
        return res;
    }
};