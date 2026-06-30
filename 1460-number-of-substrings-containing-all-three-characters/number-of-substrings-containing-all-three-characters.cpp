class Solution {
public:
    int numberOfSubstrings(string s) {
        int a, b, c;
        a = b = c = 0;
        int n = s.length();
        int j = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            if (s[i] == 'b') b++;
            if (s[i] == 'c') c++;
            if (a > 0 && b > 0 && c > 0) {
                ans += (n - i);
                if (s[j] == 'a') a--;
                if (s[j] == 'b') b--;
                if (s[j] == 'c') c--;
                if (s[i] == 'a') a--;
                if (s[i] == 'b') b--;
                if (s[i] == 'c') c--;
                j++;
                i--;
                continue;
            }
        }
        return ans;
    }
};