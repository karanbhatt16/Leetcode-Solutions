class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n, -1);
        for (int i = 1; i < n; i++) {
            int maxx = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (abs(nums[i] - nums[j]) <= target) {
                    if (arr[j] == -1) {if (j == 0) maxx = max(maxx, 1);}
                    else maxx = max(maxx, arr[j] + 1);
                }
            }
            arr[i] = maxx;
        }
        return arr[n - 1];
    }
};