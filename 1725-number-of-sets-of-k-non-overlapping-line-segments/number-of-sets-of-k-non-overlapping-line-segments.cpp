using ll = long long;
class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numberOfSets(int n, int K) {
        vector<vector<long long>> dp(K + 1, vector<long long> (n + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int k = 1; k <= K; k++) {
            vector<long long> prevRow(n + 1, 0);
            for (int idx = n - 1; idx >= 0; idx--) {
                prevRow[idx] = (prevRow[idx + 1] + dp[k - 1][idx]) % MOD;
            }
            for (int i = n - 1; i >= 0; i--) {
                long long skip = dp[k][i + 1] % MOD;
                long long take = prevRow[i + 1] % MOD;

                dp[k][i] = (take + skip) % MOD;
            }
        }
        return dp[K][0];
    }
};