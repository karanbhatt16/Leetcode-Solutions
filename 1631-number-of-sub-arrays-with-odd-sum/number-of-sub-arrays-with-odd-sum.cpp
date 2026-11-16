class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        vector<int> odd(n + 1, 0);
        odd[0] = 0;
        for (int i = 1; i <= n; i++) {
            if ((prefix[i] % 2) == 1) {
                odd[i] = 1;
            }
            odd[i] += odd[i - 1];
        }

        long long count = 0;
        int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            if (prefix[i] % 2 == 0) {
                count = (count + odd[i - 1]) % MOD;
            } else {
                count = (count + i - odd[i - 1]) % MOD;
            }
        }
        return (int)count;
    }
};