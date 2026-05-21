class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.length();
        string ans = "";
        int x = numRows;
        for (int i = 0; i < numRows; i++) {
            int j = i;
            if (i == 0 || i == numRows - 1) {
                while (j < n) {
                    ans += s[j];
                    j += (numRows - 1) * 2;
                }
            } else {
                while (j < n) {
                    ans += s[j];
                    j += (x - 1) * 2;
                    if (j < n) ans += s[j];
                    j += (numRows - 1) * 2 - (x - 1) * 2;
                }
            }
            x--;
        }
        return ans;
    }
};