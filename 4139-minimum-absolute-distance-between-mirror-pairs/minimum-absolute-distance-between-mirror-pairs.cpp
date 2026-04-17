class Solution {
public:
    int reverse(int ele) {
        int ans = 0; 
        while (ele != 0) {
            int rem = ele % 10;
            ele /= 10;
            ans = ans * 10 + rem;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++) {
            res = min(res, abs((i - (mp[nums[i]] == 0 ? INT_MAX : mp[nums[i]])) + 1));
            int rev = reverse(nums[i]);
            mp[rev] = i + 1;
        }
        if (res == n) {
            return -1;
        }
        return res;
    }
};