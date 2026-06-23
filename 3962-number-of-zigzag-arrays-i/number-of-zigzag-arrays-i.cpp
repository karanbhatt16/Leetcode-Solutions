const int MOD = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int N, int l, int r) {
        int m = r - l + 1; 
        vector<int> prev_inc(m, 1);
        vector<int> prev_dec(m, 1);
        
        for (int n = 1; n < N; n++) {
            vector<int> prefix(m + 1, 0);
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = (prefix[i] + prev_inc[i]) % MOD;
            }
            vector<int> curr_dec(m);
            for (int x = 0; x < m; x++) {
                curr_dec[x] = prefix[x]; 
            }
            
            vector<int> suffix(m + 1, 0);
            for (int i = m - 1; i >= 0; i--) {
                suffix[i] = (suffix[i + 1] + prev_dec[i]) % MOD;
            }
            vector<int> curr_inc(m);
            for (int x = 0; x < m; x++) {
                curr_inc[x] = suffix[x + 1]; 
            }
            
            prev_inc.swap(curr_inc);
            prev_dec.swap(curr_dec);
        }
        
        long ans = 0;
        for (int x = 0; x < m; x++) {
            ans = (ans + prev_inc[x]) % MOD;
        }
        ans = ans * 2 % MOD;
        return ans;
    }
};