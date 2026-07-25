class Solution {
public:
    int maxProduct(int n) {
        int mx = 0;
        int mx2 = 0;
        while (n != 0) {
            int rem = n % 10;
            if (rem > mx) {
                mx2 = mx;
                mx = rem;
            } else if (rem >= mx2) {
                mx2 = rem;
            }
            n = n / 10;
        }
        return mx * mx2;
    }
};