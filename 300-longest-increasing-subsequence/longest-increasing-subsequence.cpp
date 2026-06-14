class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
            
        vector<int> ahead(n + 2, 0), curr(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                int take = 0;
                int notTake = 0;

                notTake = ahead[j];

                if (j == 0 || arr[i] > arr[j - 1]) {
                    take = 1 + ahead[i + 1];
                }

                curr[j] = max(take, notTake);
            }
            ahead = curr;
        }

        return ahead[0];
    }
};