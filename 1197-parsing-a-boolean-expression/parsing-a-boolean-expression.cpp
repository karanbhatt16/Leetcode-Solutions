class Solution {
private:
    int res;

    bool orsolve(string& s, int& i) {
        stack<char> st;
        bool ans = false;
        st.push(s[i]);
        i++;
        while (!st.empty()) {
            if (s[i] == 't') {
                ans = ans | true;
            }
            if (s[i] == 'f') {
                ans = ans | false;
            }
            if (s[i] == '!' || s[i] == '|' || s[i] == '&') {
                ans = ans | solve(s, i);
            }
            if (s[i] == ')') {
                st.pop();
            }
            i++;
        }
        return ans;
    }

    bool andsolve(string& s, int& i) {
        stack<char> st;
        bool ans = true;
        st.push(s[i]);
        i++;
        while (!st.empty()) {
            if (s[i] == 't') {
                ans = ans & true;
            }
            if (s[i] == 'f') {
                ans = ans & false;
            }
            if (s[i] == '!' || s[i] == '|' || s[i] == '&') {
                ans = ans & solve(s, i);
            }
            if (s[i] == ')') {
                st.pop();
            }
            i++;
        }
        return ans;
    }

    bool solve(string& s, int& i) {
        while (s[i] == '(') {
            i++;
        }
        while (s[i] == ')') {
            i++;
        }
        if (s[i] == '!') {
            i+=2;
            bool ans = !(solve(s, i));
            i++;
            return ans;
        }
        if (s[i] == '|') {
            i++;
            return orsolve(s, i);
        }
        if (s[i] == '&') {
            i++;
            return andsolve(s, i);
        }
        if (s[i] == 't') {
            i++;
            return true;
        } else {
            i++;
            return false;
        }
    }
public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return solve(expression, i);
    }
};