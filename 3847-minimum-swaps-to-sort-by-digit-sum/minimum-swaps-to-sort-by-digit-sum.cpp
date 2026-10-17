class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> a(n);

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int num = nums[i];
            mp[nums[i]] = i;
            while (num != 0) {
                sum += (num % 10);
                num /= 10;
            }
            a[i] = {nums[i], sum, i};
        }

        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            if (x[1] == y[1]) {
                return x[0] < y[0];
            }
            return x[1] < y[1];
        });

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i][2] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = a[j][2];
                cycleSize++;
            }
            swaps += cycleSize - 1;
        }
        return swaps;
    }
};