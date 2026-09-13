class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            reverse(grid[i].begin(), grid[i].begin() + rowShift[i]);
            reverse(grid[i].begin() + rowShift[i], grid[i].end());
            reverse(grid[i].begin(), grid[i].end());
        }
        vector<vector<int>> transpose(n, vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transpose[i][j] = grid[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(transpose[i].begin(), transpose[i].begin() + colShift[i]);
            reverse(transpose[i].begin() + colShift[i], transpose[i].end());
            reverse(transpose[i].begin(), transpose[i].end());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[j][i] = transpose[i][j];
            }
        }
        return grid;
    }
};