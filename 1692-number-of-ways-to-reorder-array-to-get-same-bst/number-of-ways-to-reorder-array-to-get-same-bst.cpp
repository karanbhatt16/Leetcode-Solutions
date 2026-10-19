class Solution {
private:
    int MOD = 1e9 + 7;
    long long solve(vector<int>& nums, vector<vector<long long>>& comb) {
        int n = nums.size();
        if (n < 3) return 1;
        vector<int> leftArr, rightArr;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                leftArr.push_back(nums[i]);
            } else {
                rightArr.push_back(nums[i]);
            }
        }

        long long x = solve(leftArr, comb);
        long long y = solve(rightArr, comb);
        long long z = comb[n - 1][leftArr.size()];
        return (((x * y) % MOD) * z) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> comb(n + 1, vector<long long> (n + 1, 1));
        for (int i = 1; i <= n; i++) {
            comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        return (int)solve(nums, comb) - 1;
    }
};