class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> temp;
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (temp.size() == 0) {
                temp.insert(temp.begin(), i);
                continue;
            }
            if (nums[i] > nums[temp[0]]) {
                temp.insert(temp.begin(), i);
            } else {
                int ans = 0;
                int target = nums[i];
                int left = 0;
                int right = temp.size() - 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    
                    if (nums[temp[mid]] < target) {
                        right = mid - 1;
                    } else {
                        if (nums[temp[ans]] >= nums[temp[mid]]) {
                            ans = mid;
                        }
                        left = mid + 1;
                    }
                }
                res = max(res, temp[ans] - i);
            }
        }
        return res;
    }
};