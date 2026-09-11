class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j] && !visited[j]) {
                    visited[j] = 1;
                    break;
                }
                if (j == n - 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};