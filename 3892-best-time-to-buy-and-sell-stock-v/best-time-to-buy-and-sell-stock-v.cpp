class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (3, vector<long long> (K + 1, 0)));

        for (int k = 1; k <= K; k++) {
            dp[n - 1][1][k] = prices[n - 1];
            dp[n - 1][2][k] = - prices[n - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                dp[i][0][k] = max({dp[i + 1][0][k],
                dp[i + 1][1][k] - prices[i],
                dp[i + 1][2][k] + prices[i]});

                dp[i][1][k] = max(dp[i + 1][1][k],
                dp[i + 1][0][k - 1] + prices[i]);

                dp[i][2][k] = max(dp[i + 1][2][k], 
                dp[i + 1][0][k - 1] - prices[i]);
            }
        }
        return dp[0][0][K];
    }
};