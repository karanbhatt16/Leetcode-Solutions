class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n, 1);
        vector<int> count(n, 1);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && arr[i] < arr[j] + 1) {
                    arr[i] = arr[j] + 1;
                    count[i] = count[j];
                } else if (nums[i] > nums[j] && arr[i] == arr[j] + 1) {
                    count[i] += count[j];
                }
            }
            maxi = max(maxi, arr[i]);
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == maxi) {
                c += count[i];
            }
        }
        return c;
    }
};