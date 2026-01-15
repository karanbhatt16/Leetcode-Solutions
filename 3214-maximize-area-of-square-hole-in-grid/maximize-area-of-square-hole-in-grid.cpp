class Solution {
public:

    int solve(vector<int>& arr, int x) {
        int count = 0;
        int ans = 0;
        int prev = arr[0] - 1;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1 || arr[i] == x + 2) {
                ans = max(ans, count);
                count = 1;
                continue;
            }

            if (arr[i] - prev == 1) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
            prev = arr[i];
        }

        ans = max(ans, count);

        return ans;

    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int horizontal = solve(hBars, n);
        int vertical = solve(vBars, m);

        int length = min(horizontal, vertical);

        return (length + 1) * (length + 1);

    }
};