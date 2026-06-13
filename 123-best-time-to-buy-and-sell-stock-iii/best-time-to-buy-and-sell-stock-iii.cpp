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
        vector<vector<int>> ahead(2, vector<int> (2, 0)), curr(2, vector<int> (2, 0));
        for (int i = n - 1; i >=0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (j) {
                        int profit1 = ahead[0][k] - prices[i];
                        int profit2 = ahead[1][k];
                        curr[j][k] = max(profit1, profit2);
                    } else {
                        int profit1 = prices[i];
                        if (k > 0) {
                            profit1 = ahead[1][k - 1] + prices[i];
                        }
                        int profit2 = ahead[0][k];
                        curr[j][k] = max(profit1, profit2);
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][1];
    }
};