class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[diff[i]]++;
        }

        vector<pair<long long, long long>> v(n);
        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }

        reverse(v.begin(), v.end());
        v.push_back({0, 0});
        long long ans = 0;
        int k = k1 + k2;
        for (int i = 0; i < v.size() - 1; i++) {
            if (k >= (v[i].first - v[i + 1].first) * v[i].second) {
                v[i + 1].second += v[i].second;
                k -= (v[i].first - v[i + 1].first) * v[i].second;
                v[i].second = 0;
            } else {
                if (k != 0) {
                    int x = k / v[i].second;
                    k = k % v[i].second;
                    v[i].first -= x;
                    ans += k * (v[i].first - 1) * (v[i].first - 1);
                    ans += (v[i].second - k) * v[i].first * v[i].first;
                    k = 0;
                } else {
                    ans += v[i].second * v[i].first * v[i].first;
                }
            }
        }
        return ans;
    }
};