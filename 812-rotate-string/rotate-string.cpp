class Solution {
public:
    bool rotateString(string s, string goal) {
        string check = s + s;
        int n = check.length();
        if (goal.size() != n / 2) return false;
        int j = 0;
        for (int i = 0; i < n; i++) {
            int k = i;
            while (j < goal.size() && k < n && check[k] == goal[j]) {
                j++;
                k++;
            }
            if (j == goal.size()) {
                return true;
            } else {
                j = 0;
            }
        }
        return false;
    }
};