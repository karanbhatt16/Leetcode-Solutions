class Solution {
public:
    char processStr(string s, long long k) {
        long long L = 0;
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                L = L * 2;
            } else if (s[i] == '*') {
                L -= 1;
                if (L < 0) L = 0;
            } else if (s[i] == '%') {
                L = L;
            } else {
                L += 1;
                ans += s[i];
            }
        }
        long long count;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                L = L / 2;
                if (k >= L) k = k - L;
            } else if (s[i] == '*') {
                L += 1;
                if (k >= L - 1) return '.';
            } else if (s[i] == '%') {
                if (k < L) k = L - k - 1;
            } else {
                L--;
                if (L == k) return s[i];
            }
        }
        return '.';
    }
};