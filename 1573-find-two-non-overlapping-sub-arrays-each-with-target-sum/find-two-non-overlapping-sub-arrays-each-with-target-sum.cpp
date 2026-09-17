class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int length = n;
        vector<int> minL(n, n);
        int j = n - 1;
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            while (sum > target) {
                sum -= arr[j];
                j--;
            }
            if (sum == target) {
                length = min(length, j - i + 1);
            }
            minL[i] = length;
        }

        for (int i = 0; i < n; i++) {
            cout << minL[i] << " ";
        }
        int len = n + 1;
        sum = 0;
        j = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += arr[i];

            while (sum > target) {
                sum -= arr[j];
                j++;
            }

            if (sum == target) {
                len = min(len, (i - j + 1 + minL[i + 1]));
            }
        }
        return len > n ? -1 : len;
    }
};