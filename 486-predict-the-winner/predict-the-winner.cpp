class Solution {
private:
    int solve(vector<int>& nums, int i, int j, bool x) {
        if (i == j) {
            return nums[j];
        }
        if (x) {
            int a = nums[i] + solve(nums, i + 1, j, !x);
            int b = nums[j] + solve(nums, i, j - 1, !x);
            return max(a, b);
        } else {
            int a = solve(nums, i + 1, j, !x);
            int b = solve(nums, i, j - 1, !x);
            return min(a, b);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (2 * solve(nums, 0, n - 1, true) >= sum) {
            return true;
        }
        return false;
    }
};