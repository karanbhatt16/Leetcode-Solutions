class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int a = ((1 << i) & left);
            int b = ((1 << i) & right);
            if (a != 0 && b != 0) {
                if ((right - left) < (1 << i)) {
                    ans += (1 << i);
                }
            }
        }
        return ans;
    }
};