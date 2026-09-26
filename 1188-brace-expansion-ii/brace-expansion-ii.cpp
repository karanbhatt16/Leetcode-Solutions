class Solution {
private:
    int n;
    int idx;
    string exp;
    set<string> unionn() {
        set<string> result;
        while (true) {
            set<string> temp = concatenation();
            result.insert(begin(temp), end(temp));
            if (idx < n && exp[idx] == ',') idx++;
            else break;
        }
        return result;
    }
    set<string> concatenation() {
        set<string> result = {""};
        while (idx < n && (exp[idx] == '{' || isalpha(exp[idx]))) {
            set<string> temp = getunit();
            set<string> concatres;
            for (const string& left: result) {
                for (const string& right: temp) {
                    concatres.insert(left + right);
                }
            }
            result = concatres;
        }
        return result;
    }
    set<string> getunit() {
        set<string> result;
        if (exp[idx] == '{') {
            idx++;
            result = unionn();
        } else {
            result = {string(1, exp[idx])};
        }
        idx++;
        return result;
    }
public:
    vector<string> braceExpansionII(string expression) {
        n = expression.length();
        idx = 0;
        exp = expression;
        set<string> s = unionn();
        vector<string> result(begin(s), end(s));
        return result;
    }
};