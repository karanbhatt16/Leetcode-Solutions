class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int j = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            while (mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};