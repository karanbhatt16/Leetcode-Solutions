class Solution {
private:
    int solve(vector<int>& coins, int target, int i, vector<vector<int>>& dp) {

        if (i == -1) {
            return target == 0;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int notPick = solve(coins, target, i - 1, dp);
        int pick = 0;

        if (coins[i] <= target) {
            pick = solve(coins, target - coins[i], i, dp);
        }

        return dp[i][target] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return solve(coins, amount, n - 1, dp);
    }
};