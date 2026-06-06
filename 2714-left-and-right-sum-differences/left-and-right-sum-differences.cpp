class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();
        vector<int> leftSum(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            leftSum[i] = sum;
            sum += nums[i];
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = abs(sum - leftSum[i] * 2 - nums[i]);
        }
        return ans;
    }
};