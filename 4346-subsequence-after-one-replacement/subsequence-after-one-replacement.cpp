class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m < n) return false;

        vector<int> prefix(n, m);
        vector<int> suffix(n, -1);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && s[i] != t[j]) j++;
            if (j == m) break;
            prefix[i] = j;
            j++;
        }

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && s[i] != t[j]) j--;
            if (j < 0) break;
            suffix[i] = j;
            j--;
        }

        for (int i = 0; i < n; i++) {
            int left = i == 0 ? -1 : prefix[i - 1];
            int right = i == n - 1 ? m : suffix[i + 1];

            if (left + 1 < right) return true;
        }
        return false;
    }
};