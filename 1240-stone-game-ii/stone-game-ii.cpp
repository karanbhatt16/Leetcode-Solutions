class Solution {
private:
    int solve(vector<int>& piles, int M, int i, vector<vector<int>>& dp) {
        if (M < piles.size() && i < piles.size() && dp[M][i] != -1) {
            return dp[M][i];
        }
        int sum = 0;
        int ans = -1e7;
        for (int X = 0; X < 2 * M; X++) {
            if (i + X >= piles.size()) break;
            sum += piles[i + X];
            ans = max(ans, (sum - solve(piles, max(M, X + 1), i + X + 1, dp)));
        }
        if (ans == -1e7) return 0;
        return dp[M][i] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(2*n, vector<int> (2*n, -1));
        int val = solve(piles, 1, 0, dp);
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += piles[i];
        }
        return (total_sum + val) / 2;
    }
};