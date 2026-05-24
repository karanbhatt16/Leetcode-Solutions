class Solution {
private:
    int solve (vector<int>& arr, vector<int>& dp, int i, int d) {

        if (dp[i] != -1) {
            return dp[i];
        }

        //left

        int x = i - d < 0 ? 0 : i - d;
        int left = 0;
        for (int j = i - 1; j >= x; j--) {
            if (arr[j] < arr[i]) {
                left = max(left, solve(arr, dp, j, d));
            } else {
                break;
            }
        }

        //right
        
        int n = arr.size();
        x = i + d > n - 1 ? n - 1 : i + d;
        int right = 0;
        for (int j = i + 1; j <= x; j++) {
            if (arr[j] < arr[i]) {
                right = max(right, solve(arr, dp, j, d));
            } else {
                break;
            }
        }

        return dp[i] = max(left, right) + 1;

    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 0;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            ans = max(solve (arr, dp, i, d), ans);
        }
        return ans;
    }
};