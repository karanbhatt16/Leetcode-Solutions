class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        int mul = value;
        for (int i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                mul = i;
                break;
            }
        }
        int x = value - mul;
        if (x - (index - 1) * 2 <= 0 || value <= 1) {
            return -1;
        }
        long long ans = value + mul;
        ans = ans + (n - index - 2) * 2;
        return ans;
    }
};