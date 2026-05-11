class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            while(num != 0) {
                int rem = num % 10;
                ans.push_back(rem);
                num = num / 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};