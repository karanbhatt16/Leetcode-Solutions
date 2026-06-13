class Solution {
private:
    int solve(vector<int>& prices, int i, int x, int buy, vector<vector<vector<int>>>& dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (x >= 0) {
            if (dp[i][buy][x] != -1) {
                return dp[i][buy][x];
            }
            if (buy) {
                int profit1 = solve(prices, i + 1, x, 0, dp) - prices[i];
                int profit2 = solve(prices, i + 1, x, 1, dp);
                return dp[i][buy][x] = max(profit1, profit2);
            } else {
                int profit1 = solve(prices, i + 1, x - 1, 1, dp) + prices[i];
                int profit2 = solve(prices, i + 1, x, 0, dp);
                return dp[i][buy][x] = max(profit1, profit2);
            }
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2, -1)));
        return solve(prices, 0, 1, 1, dp);
    }
};