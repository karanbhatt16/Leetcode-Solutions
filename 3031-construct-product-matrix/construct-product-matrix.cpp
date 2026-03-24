class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long prod = 1;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        int M = 12345;
        vector<vector<int>> prefix(n, vector<int> (m, 0));
        vector<vector<int>> postfix(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = prod;
                prod = (prod * (long long)grid[i][j]) % M;
            }
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                postfix[i][j] = prod;
                prod = (prod * (long long)grid[i][j]) % M;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = (prefix[i][j] * postfix[i][j]) % M;
            }
        }
        return grid;
    }
};