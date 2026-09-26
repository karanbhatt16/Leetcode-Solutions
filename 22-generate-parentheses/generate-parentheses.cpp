class Solution {
private:
    vector<string> result;
    void solve(int open, int close, string& s) {
        if (open == 0 && close == 0) {
            result.push_back(s);
            return;
        }
        if (open < 0 || close < 0) return;
        if (close < open) return;
        string x = s + '(';
        solve(open - 1, close, x);
        x = s + ')';
        solve(open, close - 1, x);
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        solve(n, n, s);
        return result;
    }
};