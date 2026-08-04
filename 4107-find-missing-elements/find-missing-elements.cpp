class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = nums[0];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (nums[i] > k) {
                ans.push_back(k);
                k++;
            }
            k++;
        }
        return ans;
    }
};