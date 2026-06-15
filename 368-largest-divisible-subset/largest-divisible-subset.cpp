class Solution {
private:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i + 1][j + 1] != -1) {
            return dp[i + 1][j + 1];
        }

        int a = solve(nums, i + 1, j, dp);
        int b = 0;
        if (j == -1 || nums[i] % nums[j] == 0) {
            b = 1 + solve(nums, i + 1, i, dp);
        }
        return dp[i + 1][j + 1] = max(a, b);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> idxarr(n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            idxarr[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 >= dp[i]) {
                    dp[i] = dp[j] + 1;
                    idxarr[i] = j;
                }
            }
        }

        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] > dp[idx]) {
                idx = i;
            }
        }

        while (idx != idxarr[idx]) {
            ans.push_back(nums[idx]);
            idx = idxarr[idx];
        }
        ans.push_back(nums[idx]);


        
        return ans;
    }
};