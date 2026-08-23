class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left = 0;
        int sum1 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                left++;
            } else {
                sum1 += (num[i] - '0');
            }
        }

        int right = 0;
        int sum2 = 0;
        for (int i = (n + 1) / 2; i < n; i++) {
            if (num[i] == '?') {
                right++;
            } else {
                sum2 += (num[i] - '0');
            }
        }

        if (left + right == 1) {
            return true;
        }
        if ((sum1 > sum2 && left > right) || (sum2 > sum1 && right > left)) return true;
        int missing1 = (abs(left - right) + 1) / 2;
        int missing2 = (abs(left - right) / 2);
        if (missing1 - missing2 == 1) {
            return true;
        }
        int sum = abs(sum1 - sum2);

        if (sum == missing2 * 9 ) {
            return false;
        }
        return true;
    }
};