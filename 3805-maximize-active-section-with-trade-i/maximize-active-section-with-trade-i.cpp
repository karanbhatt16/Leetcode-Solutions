class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = '1' + s + '1';
        int n = s.length();
        int prev = 0;
        int ans = 0;
        int one = 0;
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                count++;
            } else {
                one++;
                if (prev != 0 && count != 0) {
                    ans = max(ans, prev + count);
                    prev = count;
                }
                if (prev == 0) {
                    prev = count;
                }
                count = 0;
            }
        }
        return ans + one - 1;
    }
};