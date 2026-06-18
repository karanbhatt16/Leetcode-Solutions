class Solution {
private:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (i + 1 == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mincost = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int cost = cuts[j] - cuts[i] + solve(cuts, i, k, dp) + solve(cuts, k, j, dp);
            mincost = min(mincost, cost);
        }
        return dp[i][j] = mincost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(103, vector<int> (103, -1));
        return solve(cuts, 0, cuts.size() - 1, dp);
    }
};