class Solution {
public:
    int reverse (int n) {
        int ans = 0;
        while (n != 0) {
            int rem = n % 10;
            n /= 10;
            ans = ans * 10 + rem;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};