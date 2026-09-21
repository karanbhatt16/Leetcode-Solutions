class Solution {
private:
    void solve(vector<int>& nums, int k, int i, vector<vector<long long>>& ans) {
        if (i > nums.size()) return;
        ans[i][nums[i - 1]]++;
        for (int j = 0; j < k; j++) {
            ans[i][(nums[i - 1] * j) % k] += ans[i - 1][j];
        }
        solve(nums, k, i + 1, ans);
    }
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % k;
        }

        vector<vector<long long>> ans(n + 1, vector<long long> (k, 0));
        solve(nums, k, 1, ans);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k; j++) {
                ans[i][j] += ans[i - 1][j];
            }
        }
        return ans[n];
    }
};