class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        string ans = "";
        int len = 0;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = i;
            while (left >= 0 && right < n && left <= right) {
                if (s[left] != s[right]) break;
                left--;
                right++;
            }
            if (len < right - left - 1) {
                len = right - left - 1;
                end = right - 1;
                start = left + 1;
            }

            if (i < n - 1) {
                left = i;
                right = i + 1;
                while (left >= 0 && right < n && left < right) {
                    if (s[left] != s[right]) break;
                    left--;
                    right++;
                }
                if (len < right - left - 1) {
                    len = right - left - 1;
                    end = right - 1;
                    start = left + 1;
                }
            }
        }
        for (int i = start; i <= end; i++) {
            ans += s[i];
        }
        return ans;
    }
};