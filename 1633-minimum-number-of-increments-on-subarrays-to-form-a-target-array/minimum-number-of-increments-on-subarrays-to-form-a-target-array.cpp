class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int start = 0;
        int n = target.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (target[i] > start) {
                ans += target[i] - start;
            }
            start = target[i];
        }
        return ans;
    }
};