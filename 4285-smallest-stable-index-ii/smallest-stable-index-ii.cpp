class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxx(n);
        vector<int> minn(n);

        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            maxx[i] = mx;
        }
        int mn = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            minn[i] = mn;
        }

        for (int i = 0; i < n; i++) {
            if (maxx[i] - minn[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};