class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(limit * 2 + 2, 0);
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int a = nums[left];
            int b = nums[right];
            diff[0] += 2;
            diff[min(a, b)+1] -= 2;
            diff[min(a, b) + 1] += 1;
            diff[a + b] += -1;
            diff[a + b + 1] += 1;
            diff[max(a, b) + limit + 1] -= 1;
            diff[max(a, b) + limit + 1] += 2;
            left++;
            right--;
        }
        int csum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < diff.size(); i++) {
            csum += diff[i];
            diff[i] = csum;
            ans = min(ans, diff[i]);
        }
        return ans;
    }
};