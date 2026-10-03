class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        int n = s.size();
        int start = 0;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else {
                if (count == 0) {
                    start = i + 1;
                } else count--;
            }
            if (count == 0) {
                ans = max(ans, i - start + 1);
            }
        }
        count = 0;
        start = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                count++;
            } else {
                if (count == 0) {
                    start = i - 1;
                } else count--;
            }
            if (count == 0) {
                ans = max(ans, start - i + 1);
            }
        }
        return ans;
    }
};