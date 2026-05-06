class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        for (int i = 0; i < m; i++) {
            int empty = 0;
            for (int j = 0; j < n; j++) {
                if (boxGrid[i][j] == '.') {
                    boxGrid[i][j] = boxGrid[i][empty];
                    boxGrid[i][empty] = '.';
                    empty++;
                } else if (boxGrid[i][j] == '*') {
                    empty = j + 1;
                }
            }
        }
        vector<vector<char>> ans(n, vector<char> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                ans[i][m - j - 1] = boxGrid[j][i];
            }
        }
        return ans;
    }
};