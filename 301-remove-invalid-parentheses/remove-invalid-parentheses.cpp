class Solution {
private:
    set<string> ans;
    string temp = "";
    int n;
    bool isValid(string& s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }
    void solve(string& s, int i, int k) {
        if (i == s.length()) {
            if (k == 0 && isValid(temp)) {
                ans.insert(temp);
            }
            return;
        }
        if (k == 0) {
            string x = temp;
            if (isValid(x)) {
                ans.insert(x);
            }
            return;
        }
        if (s[i] < 'a' || s[i] > 'z') solve(s, i + 1, k);
        temp.push_back(s[i]);
        solve(s, i + 1, k - 1);
        temp.pop_back();
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int count = 0;
        int invalid = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                if (count > 0) count--;
                else invalid++;
            }
        }
        invalid += count;
        int k = n - invalid;
        solve(s, 0, k);
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};