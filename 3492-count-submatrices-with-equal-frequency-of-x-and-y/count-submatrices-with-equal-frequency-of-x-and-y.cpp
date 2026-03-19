class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> arr(grid.size(), vector<int> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size();j++) {
                arr[i][j] = grid[i][j] == 'X' ? 1 : grid[i][j] == 'Y' ? -1 : 0;
                if (i > 0) {
                    if (j > 0) {
                        arr[i][j] += (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
                    } else {
                        arr[i][j] += arr[i - 1][j];
                    }
                } else {
                    if (j > 0) {
                        arr[i][j] += arr[i][j - 1];
                    }
                }
            }
        }
        int count = 0;
        int minx = grid.size();
        int miny = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (arr[i][j] != 0) {
                    minx = min(minx, i);
                    miny = min(miny, j);
                }
                if (arr[i][j] == 0 && i >= minx && j >= miny) count++;
            }
        }
        return count;
    }
};