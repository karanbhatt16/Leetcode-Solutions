class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });

        vector<int> groups(n);
        int group = 0;

        vector<vector<int>> final_arr(n);
        for (int i = 0; i < n; i++) {
            final_arr[i].push_back(1);
        }
        int prev = arr[0].first;
        for (int i = 0; i < n; i++) {
            if (arr[i].first - prev <= limit) {
                groups[arr[i].second] = group;
                final_arr[group].push_back(arr[i].second);
            } else {
                group++;
                groups[arr[i].second] = group;
                final_arr[group].push_back(arr[i].second);
            }
            prev = arr[i].first;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[final_arr[groups[i]][final_arr[groups[i]][0]]];
            final_arr[groups[i]][0]++;
        }
        return ans;
    }
};