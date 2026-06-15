class Solution {
private:
    long long solve(vector<int>& prices, int k, int i, int buy, vector<vector<vector<long long>>>& dp) {
        if (k == 0) {
            return 0;
        }
        if (i == prices.size() - 1) {
            if (buy == 1) {
                return prices[i];
            } else if (buy == 2) {
                return -prices[i];
            }
            return 0;
        }
        if (dp[i][buy][k] != -1) {
            return dp[i][buy][k];
        }
        long long profit = 0;
        if (buy == 0) {
            profit = max({solve(prices, k, i + 1, 0, dp),
            solve(prices, k, i + 1, 1, dp) - prices[i],
            solve(prices, k, i + 1, 2, dp) + prices[i]});
        } else if (buy == 1) {
            profit = max(solve(prices, k, i + 1, 1, dp),
            solve(prices, k - 1, i + 1, 0, dp) + prices[i]);
        } else {
            profit = max(solve(prices, k, i + 1, 2, dp), 
            solve(prices, k - 1, i + 1, 0, dp) - prices[i]);
        }
        return dp[i][buy][k] = profit;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (3, vector<long long> (k + 1, -1)));
        return solve(prices, k, 0, 0, dp);
    }
};