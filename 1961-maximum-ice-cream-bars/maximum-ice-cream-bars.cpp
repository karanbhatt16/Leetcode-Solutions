class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = *max_element(costs.begin(), costs.end());
        vector<long long> arr(n + 1, 0);

        for (int i = 0; i < costs.size(); i++) {
            arr[costs[i]]++;
        }

        int ans = 0;

        for (long long i = 1; i < n + 1; i++) {
            if (coins >= i * arr[i]) {
                coins -= (i * arr[i]);
                ans += arr[i];
            } else if (coins >= i) {
                ans += coins / i;
                coins -= (i * (coins / i));
            }
        }
        return ans;
    }
};