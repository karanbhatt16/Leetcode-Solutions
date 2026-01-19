class Solution {
public:

    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> prefixRow(grid.begin(), grid.end());
        vector<vector<int>> prefixCol(grid.begin(), grid.end());
        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                prefixRow[i][j] += prefixRow[i][j - 1];
            }
        }
        for (int i = 0; i < col; i++) {
            for (int j = 1; j < row; j++) {
                prefixCol[j][i] += prefixCol[j - 1][i];
            }
        }
        int side = min(row, col);
        for (int k = side; k >= 2; k--) {
            for (int i = 0; i + k - 1 < row; i++) {
                for (int j = 0; j + k - 1 < col; j++) {
                    int targetSum = prefixRow[i][j + k - 1] - prefixRow[i][j] + grid[i][j];
                    int diagonal = 0;
                    int antidiagonal = 0;
                    bool flag = true;
                    for (int x = 0; x < k; x++) {
                        int row1 = prefixRow[i + x][j + k - 1] - prefixRow[i + x][j] + grid[i + x][j]; 
                        int col1 = prefixCol[i + k - 1][j + x] - prefixCol[i][j + x] + grid[i][j + x];
                        diagonal += grid[i + x][j + x];
                        antidiagonal += grid[i + x][j + k - 1 - x];
                        if (targetSum != row1 || targetSum != col1) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false) {
                        continue;
                    }
                    if (targetSum == diagonal && targetSum == antidiagonal) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};