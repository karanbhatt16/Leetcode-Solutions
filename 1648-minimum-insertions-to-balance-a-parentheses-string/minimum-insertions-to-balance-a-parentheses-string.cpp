class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                if (s[i] == s[i + 1]) {
                    if (!st.empty()) st.pop();
                    else ans++;
                    i++;
                } else {
                    if (!st.empty()) st.pop();
                    else {
                        ans++;
                    }
                    ans++;
                }
            }
            if (i == n - 2) {
                if (s[i + 1] == ')') {
                    if (!st.empty()) {
                        st.pop();
                        ans++;
                    } else {
                        ans += 2;
                    }
                } else {
                    st.push('(');
                }
            }
        }
        return ans + st.size() * 2;
    }
};