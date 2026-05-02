class Solution {
private:

public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            int cnt1 = 0;
            int cnt2 = 0;
            int digits = 0;
            int rev = 0;
            while (num != 0) {
                int digit = num % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    cnt1++;
                } else if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    cnt2++;
                }
                digits++;
                num = num/10;
                if (digit == 2) digit = 5;
                else if (digit == 5) digit = 2;
                else if (digit == 6) digit = 9;
                else if (digit == 9) digit = 6;
                rev = rev + digit;
            }
            if (cnt1 == 0 && cnt2) {
                if (digits % 2 != 0) {
                    ans++;
                } else if (rev != i){
                    ans++;
                }
            }
        }
        return ans;
    }
};