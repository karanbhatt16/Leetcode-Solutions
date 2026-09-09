class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        int digits = 0;
        long long num = n;
        while (num != 0) {
            num /= 10;
            digits++;
        }
        long long ans = 0;
        while (digits > 3) {
            long long comma = (digits - 1) / 3;
            long long next = 0;
            int i = comma * 3;
            while (i > 0) {
                next = next * 10 + 9;
                i--;
            }
            ans += (n - next) * comma;
            n = next;
            digits -= 3;
        }
        return ans;
    }
};