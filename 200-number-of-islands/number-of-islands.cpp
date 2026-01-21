class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        if (i != 0 && grid[i - 1][j] == '1') {
            dfs(i - 1, j, grid);
        }
        if (i != grid.size() - 1 && grid[i + 1][j] == '1') {
            dfs(i + 1, j, grid);
        }
        if (j != 0 && grid[i][j - 1] == '1') {
            dfs(i, j - 1, grid);
        }
        if (j != grid[0].size() - 1 && grid[i][j + 1] == '1') {
            dfs(i, j + 1, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(i, j, grid);
                }
            }
        }
        return island;
    }
};