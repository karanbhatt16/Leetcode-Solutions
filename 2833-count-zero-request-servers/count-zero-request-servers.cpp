
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> query;
        for (int i = 0; i < queries.size(); i++) {
            query.push_back({queries[i], i});
        }
        sort(query.begin(), query.end());

        unordered_map<int, int> mp;
        vector<int> ans(queries.size());

        int left = 0; int right = 0;

        for (int i = 0; i < queries.size(); i++) {
            while (right < logs.size() && logs[right][1] <= query[i].first) {
                mp[logs[right][0]]++;
                right++;
            }
            while (left < right && logs[left][1] < query[i].first - x) {
                mp[logs[left][0]]--;
                if (mp[logs[left][0]] == 0) mp.erase(logs[left][0]);
                left++;
            }
            ans[query[i].second] = n - mp.size();
        }
        return ans;
    }
};