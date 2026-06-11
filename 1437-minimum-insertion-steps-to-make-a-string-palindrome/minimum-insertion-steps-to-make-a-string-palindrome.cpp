class Solution {
private:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }
public:
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};