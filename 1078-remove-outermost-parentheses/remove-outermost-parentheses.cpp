class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for (auto ch : s) {
            if (ch == '(') {
                count++;
                if (count != 1) {
                    ans += ch;
                }
            } else {
                count--;
                if (count > 0) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};