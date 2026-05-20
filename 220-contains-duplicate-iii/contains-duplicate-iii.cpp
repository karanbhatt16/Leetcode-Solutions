class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<long long, long long> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            long long bucketid = num >= 0 ? (num / (valueDiff + 1)) : ((num + 1) / (valueDiff + 1) - 1);
            if (mp.find(bucketid) != mp.end()) {
                return true;
            }
            if (mp.find(bucketid - 1) != mp.end() &&
                abs(num - mp[bucketid - 1]) <= valueDiff) {
                return true;
            }
            if (mp.find(bucketid + 1) != mp.end() &&
                abs(num - mp[bucketid + 1]) <= valueDiff) {
                return true;
            }
            mp[bucketid] = nums[i];

            if (i >= indexDiff) {
                int x = nums[i - indexDiff];
                long long oldid = x >= 0 ? (x / (valueDiff + 1)) : ((x + 1) / (valueDiff + 1) - 1);
                mp.erase(oldid);
            }
        }
        return false;
    }
};