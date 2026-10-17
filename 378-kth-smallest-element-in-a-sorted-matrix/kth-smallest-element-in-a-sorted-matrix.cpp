class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            mn = min(mn, matrix[i][0]);
            mx = max(mx, matrix[i][n - 1]);
        }

        int low = mn, high = mx;
        int ans = low;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int total = 0;
            for (int i = 0; i < n; i++) {
                int ele = lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                total += ele;
            }
            if (total < k) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};