class Solution {
private:
    int cheapest_price;
    int solve(vector<vector<int>>& items, int budget, int i, vector<int>& copies, vector<vector<int>>& dp) {
        if (budget < 0) {
            return -1e9;
        }
        if (i == -1) {
            return budget / cheapest_price;
        }
        if (dp[i][budget] != -1) {
            return dp[i][budget];
        }
        int pick = copies[i] + 1 + solve(items, budget - items[i][1], i - 1, copies, dp);
        int not_pick = solve(items, budget, i - 1, copies, dp);
        return dp[i][budget] = max(pick, not_pick);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        sort(items.begin(), items.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        cheapest_price = items[0][1];
        vector<int> copies(n);
        for (int i = 0; i < n; i++) {
            int copy = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    copy++;
                }
            }
            copies[i] = copy;
        }

        vector<vector<int>> dp(n, vector<int> (budget + 1, -1));

        return solve(items, budget, n - 1, copies, dp);
    }
};