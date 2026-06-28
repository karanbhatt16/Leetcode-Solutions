class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();

        long long sum = 0;
        for (int i = 0; i < n && i < k; i++) {
            long long x = nums[i];
            if (mul > 0) {
                x *= mul;
                mul--;
            }

            sum += x;
        }
        return sum;
    }
};