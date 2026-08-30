class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn]) {
                mn = i;
            }
            if (nums[i] > nums[mx]) {
                mx = i;
            }
        }
        return min({max(mn, mx) + 1, n - min(mn, mx), min(mn, mx) + 1 + n - max(mn, mx)});
    }
};