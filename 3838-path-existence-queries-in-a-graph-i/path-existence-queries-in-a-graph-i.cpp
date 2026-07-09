class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ans(n);
        int x = 1;
        int prev = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] - prev <= maxDiff) {
                ans[i] = x;
            } else {
                x++;
                ans[i] = x;
            }
            prev = nums[i];
        }
        vector<bool> answer;
        for (auto query : queries) {
            if (ans[query[0]] == ans[query[1]]) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }
        return answer;
    }
};