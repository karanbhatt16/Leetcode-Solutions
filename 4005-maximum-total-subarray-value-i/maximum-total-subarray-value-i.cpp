class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        long long maximum = 0;
        long long minimum = INT_MAX;
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, (long long)nums[i]);
            minimum = min(minimum, (long long)nums[i]);
        }

        return k * (maximum - minimum);
    }
};