class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        sort(nums.begin(), nums.end());

        int length = 0;

        for (int i = 0; i < n; i++) {
            long long x = nums[i];

            if (mp[x] >= 1) {
                int count = 0;
                while (mp[x] >= 2) {
                    count++;
                    mp[x] -= 2;
                    x = x * x;
                }
                if (mp[x] == 1) {
                    count++;
                }
                length = max(length, 2 * count - 1);
            }
        }

        return length;
    }
};