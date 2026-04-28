class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
                sum += grid[i][j];
            }
        }
        sort(arr.begin(), arr.end());
        int minimum = INT_MAX;
        int leftsum = 0;
        int prev = arr[0];
        int length = n * m;
        if (length == 1) return 0;
        for (int i = 0; i < length; i++) {
            if ((arr[i] - prev) % x != 0) return -1;
        }
        int cnt = 0;
        for (int i = arr[0] ; i <= arr[length - 1]; i += x) {
            int right = abs(sum - (length - cnt) * i);
            int left = abs(leftsum - cnt * i);
            minimum = min(minimum, (right + left) / x);
            while (cnt < length && i >= arr[cnt]) {
                leftsum += arr[cnt];
                sum -= arr[cnt];
                cnt++;
            }
        }
        return minimum;
    }
};