class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> grid_copy(grid.begin(), grid.end());

        int count = 0; 

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i > 0) {
                    if (j > 0) {
                        grid_copy[i][j] += (grid_copy[i - 1][j] + grid_copy[i][j - 1] - grid_copy[i - 1][j - 1]);
                    } else {
                        grid_copy[i][j] += grid_copy[i - 1][j];
                    }
                } else {
                    if (j > 0) {
                        grid_copy[i][j] += grid_copy[i][j - 1];
                    }
                }
                if (grid_copy[i][j] <= k) {
                    count++;
                }
            }
        }
        return count;
    }
};