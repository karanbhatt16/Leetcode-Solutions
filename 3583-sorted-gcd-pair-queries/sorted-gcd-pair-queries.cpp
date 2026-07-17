class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
        }
        vector<long long> cnt(mx + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }

        for (int i = 1; i <= mx; i++) {
            for (int j = 2*i; j <= mx; j += i) {
                cnt[i] += cnt[j];
            }
        }

        for (int i = mx; i > 0; i--) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }

        for (int i = mx; i > 0; i--) {
            for (int j = 2 * i; j <= mx; j += i) {
                cnt[i] -= cnt[j];
            }
        }

        for (int i = 1; i <= mx; i++) {
            cnt[i] += cnt[i - 1];
            cout << cnt[i] << " ";
        }

        int m = queries.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            int idx = upper_bound(cnt.begin(), cnt.end(), queries[i]) - cnt.begin();
            ans[i] = idx;
        }
        return ans;
    }
};