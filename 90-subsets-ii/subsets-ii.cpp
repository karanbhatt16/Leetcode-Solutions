class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());

        int n = 1 << nums.size();

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++) {
                if ((1 << j) & i) {
                    temp.push_back(nums[j]);
                }
            }
            s.insert(temp);
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};