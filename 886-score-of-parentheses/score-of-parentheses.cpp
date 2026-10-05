class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                if (st.size() > 0) ans += pow(2, (st.size() - 1));
                while (s[i] == ')') {
                    st.pop();
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};