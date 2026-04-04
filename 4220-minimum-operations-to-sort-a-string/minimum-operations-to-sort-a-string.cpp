class Solution {
public:
    int minOperations(string s) {
        if (s.length() == 1) return 0;
        if (s.length() == 2) {
            if (s[0] > s[1]) return -1;
            else return 0;
        }
        char min = s[0];
        int idx1 = 0;
        char max = s[0];
        int idx2 = 0;
        bool flag = true;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] < s[i - 1]) {
                flag = false;
            }
            if (s[i] < min) {
                min = s[i];
                idx1 = i;
            }
            if (s[i] >= max) {
                max = s[i];
                idx2 = i;
            }
        }
        if (flag) return 0;
        if (idx1 == 0 || idx2 == s.length() - 1) {
            return 1;
        } else if (idx1 == s.length() - 1 && idx2 == 0) {
            return 3;
        } else if (idx1 == s.length() - 1 || idx2 == 0) {
            return 2;
        }
        return 2;
    }
};