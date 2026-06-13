class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int> (K, 0)), curr(2, vector<int> (K, 0));
        for (int i = n - 1; i >=0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < K; k++) {
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
        return ahead[1][K - 1];
    }
};