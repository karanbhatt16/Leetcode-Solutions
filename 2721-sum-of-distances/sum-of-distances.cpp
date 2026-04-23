class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<long long>> mp;
        unordered_map<long long, long long> sum;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            sum[nums[i]] += i;
        }
        vector<long long> ans(n, 0);
        for (auto it : mp) {
            long long left = 0;
            long long cnt = 0;
            long long len = it.second.size();
            if (len == 1) {
                ans[it.second[0]] = 0;
                continue;
            }
            for(int i = 0; i < it.second.size(); i++) {
                ans[it.second[i]] = abs(sum[it.first] - (it.second[i] * (len - cnt))) + abs(left - (it.second[i] * cnt));
                left += it.second[i];
                sum[it.first] -= it.second[i];
                cnt++;
            }
        }
        return ans;
    }
};