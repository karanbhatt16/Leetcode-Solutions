class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, nums[i]);
            }
            return mx;
        }

        if (k == 1) {
            int mx = -1;
            for (int i = 0; i < n; i++) {
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (nums[i] == nums[j] && i != j) {
                        flag = false;
                    }
                }
                if (flag) mx = max(mx, nums[i]);
            }
            return mx;
        }

        int a = nums[0];
        int b = nums[n - 1];
        if (a == b) return -1;
        bool first = true;
        bool second = true;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == a) first = false;
            if (nums[i] == b) second = false;
        }

        if (!first && !second) {
            return -1;
        }
        if (!first) return b;
        if (!second) return a;
        return max(a, b);
    }
};