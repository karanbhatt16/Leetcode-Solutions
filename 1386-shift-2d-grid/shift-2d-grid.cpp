class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> val(m * n);

        int t = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                val[t] = grid[i][j];
                t++;
            }
        }

        k = k % (m * n);
        k = (m * n) - k;
        reverse(val.begin(), val.begin() + k);
        reverse(val.begin() + k, val.end());
        reverse(val.begin(), val.end());

        t = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = val[t];
                t++;
            }
        }
        return grid;
    }
};