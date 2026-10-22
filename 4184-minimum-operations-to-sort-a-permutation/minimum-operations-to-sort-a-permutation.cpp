class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int inc = 0;
        int dec = 0;
        int pos1 = -1;
        int pos2 = -1;
        if (nums[0] > nums[n - 1]) {
            inc++;
        } else {
            dec++;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                pos1 = i - 1;
            } else {
                dec++;
                pos2 = i - 1;
            }
        }
        if (inc > 1 && dec > 1) {
            return -1;
        }

        if (dec == inc && inc == 1) {
            if (pos1 == -1) return 1;
            if (pos2 == -1) return 0;
        }

        if (inc == 1) {
            return min(pos1 + 2, n - pos1);
        } else {
            return min(pos2 + 1, n - pos2 + 1);
        }
        return -1;
    }
};