class Solution {
private:
    int idx = 0;
    int n;
    string ans = "";
    string reverseString(string& s) {
        string rev = "";
        while (idx < n) {
            if (s[idx] != '(' && s[idx] != ')') {
                rev += s[idx];
            } else if (s[idx] == ')') {
                idx++;
                break;
            } else {
                idx++;
                rev += reverseString(s);
                continue;
            }
            idx++;
        }
        reverse(rev.begin(), rev.end());
        return rev;
    }
    string solve(string& s) {
        while (idx < n) {
            if (s[idx] != '(') {
                ans += s[idx];
            } else {
                idx++;
                ans += reverseString(s);
                continue;
            }
            idx++;
        }
        return ans;
    }
public:
    string reverseParentheses(string s) {
        n = s.length();
        return solve(s);
    }
};