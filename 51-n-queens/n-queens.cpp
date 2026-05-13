class Solution {
private:
    vector<vector<string>> ans;
    void solve (int row, vector<int>& col, vector<int>& dia1, vector<int>& dia2, vector<string>& s, int n) {
        if (row == n) {
            ans.push_back(s);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] || dia1[row + j] || dia2[row - j + n - 1]) {
                continue;
            }

            s[row][j] = 'Q';
            col[j] = 1;
            dia1[row + j] = 1;
            dia2[row - j + n - 1] = 1;
            solve(row + 1, col, dia1, dia2, s, n);
            s[row][j] = '.';
            col[j] = 0;
            dia1[row + j] = 0;
            dia2[row - j + n - 1] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, 0);
        vector<int> dia1(n * 2, 0);
        vector<int> dia2(n * 2, 0);
        string x = "";
        for (int i = 0; i < n; i++) {
            x += ".";
        }
        vector<string> s(n, string(n, '.'));
        solve(0, col, dia1, dia2, s, n);
        return ans;
    }
};