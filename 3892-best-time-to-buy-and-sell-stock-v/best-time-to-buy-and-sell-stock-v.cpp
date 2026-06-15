class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();
        vector<vector<long long>> prev(3, vector<long long> (K + 1, 0));
        vector<vector<long long>> curr(3, vector<long long> (K + 1, 0));

        for (int k = 1; k <= K; k++) {
            prev[1][k] = prices[n - 1];
            prev[2][k] = - prices[n - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                curr[0][k] = max({prev[0][k],
                prev[1][k] - prices[i],
                prev[2][k] + prices[i]});

                curr[1][k] = max(prev[1][k],
                prev[0][k - 1] + prices[i]);

                curr[2][k] = max(prev[2][k], 
                prev[0][k - 1] - prices[i]);
            }
            prev = curr;
        }
        return prev[0][K];
    }
};