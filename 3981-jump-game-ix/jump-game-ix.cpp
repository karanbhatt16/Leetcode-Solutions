class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        int maxx = nums[0];
        vector<int> maxval(n, 0);

        for (int i = 0; i < n; i++) {
            maxx = max(maxx, nums[i]);
            maxval[i] = maxx;
        }

        vector<int> minval(n, 0);

        int minn = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            minval[i] = minn;
            minn = min(minn, nums[i]);
        }

        vector<int> ans(n, 0);

        ans[n - 1] = maxval[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (maxval[i] <= minval[i]) ans[i] = maxval[i];
            else ans[i] = ans[i + 1];
        }
        return ans;
    }
};