class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        for (int i = n - 1; i >=0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j) {
                    int profit1 = ahead[0] - prices[i];
                    int profit2 = ahead[1];
                    curr[j] = max(profit1, profit2);
                } else {
                    int profit1 = ahead[1] + prices[i] - fee;
                    int profit2 = ahead[0];
                    curr[j] = max(profit1, profit2);
                }
            }
            ahead = curr;
        }
        return ahead[1];
    }
};