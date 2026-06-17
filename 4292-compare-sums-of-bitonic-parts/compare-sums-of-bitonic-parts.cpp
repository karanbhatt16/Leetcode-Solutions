class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        long long x = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < idx || right > idx) {
            if (left < idx) {
                x += nums[left];
            }
            if (right > idx) {
                x -= nums[right];
            }
            left++;
            right--;
        }
        if (x < 0) {
            return 1;
        } else if (x > 0) {
            return 0;
        }
        return -1;
    }
};