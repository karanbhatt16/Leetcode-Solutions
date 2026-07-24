class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> xorr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xorr.insert(nums[i] ^ nums[j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < 2050; i++) {
            for (int j = 0; j < n; j++) {
                if (xorr.find(nums[j] ^ i) != xorr.end()) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};