class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }
        string ans = "";
        for (int i = 0; i < num; i++) {
            if (sum >= 9) {
                ans.push_back('9');
                sum -= 9;
            } else if (sum > 0) {
                ans.push_back(sum + '0');
                sum = 0;
            } else {
                ans.push_back('0');
            }
        }
        return ans;
    }
};