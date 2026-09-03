class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 0;
        int odd = 0;
        int smallest_even = -1;
        int smallest_odd = -1;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                even++;
                if (smallest_even == -1 || smallest_even > nums1[i]) {
                    smallest_even = nums1[i];
                }
            } else {
                odd++;
                if (smallest_odd == -1 || smallest_odd > nums1[i]) {
                    smallest_odd = nums1[i];
                }
            }
        }

        if (odd == 0 || even == 0) return true;

        if (smallest_odd < smallest_even) return true;
        return false;
    }
};