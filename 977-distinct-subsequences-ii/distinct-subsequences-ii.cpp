class Solution {
private:
    int MOD = 1e9 + 7;
    long long solve(int n, vector<int>& prev, vector<long long>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        long long total = (2 * solve(n - 1, prev, dp)) % MOD;
        if (prev[n] != 0) {
            long long duplicates = solve(prev[n] - 1, prev, dp);
            total = (total - duplicates + MOD) % MOD;
        }
        return dp[n] = total % MOD;
    }
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<long long> dp(n + 1, -1);
        vector<int> lastSeen(26, 0);
        vector<int> prev(n + 1);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n, prev, dp) - 1 + MOD) % MOD;
    }
};