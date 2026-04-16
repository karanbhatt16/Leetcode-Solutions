class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        map<int, int> mp;
        for (int i = 0; i < 2 * n; i++) {
            if (mp.find(nums[i % n]) != mp.end()) {
                left[mp[nums[i % n]]] = min(abs(i - mp[nums[i % n]]), left[mp[nums[i % n]]]);
            }
            mp[nums[i % n]] = i % n;
        }
        mp.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (mp.find(nums[i % n]) != mp.end()) {
                int ans = mp[nums[i % n]] - i;
                if (ans < 0) ans += n;
                right[mp[nums[i % n]]] = min(ans, right[mp[nums[i % n]]]);
            }
            mp[nums[i % n]] = i % n;
        }
        for (int i = 0; i < n; i++) {
            if (left[i] == INT_MAX && right[i] == INT_MAX) {
                left[i] = -1;
            } else if (left[i] == INT_MAX) {
                left[i] = right[i];
            } else if (right[i] == INT_MAX) {
                left[i] = left[i];
            } else {
                left[i] = min(left[i], right[i]);
            }
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = left[queries[i]] == 0 ? -1 : left[queries[i]];
        }
        return ans;
    }
};