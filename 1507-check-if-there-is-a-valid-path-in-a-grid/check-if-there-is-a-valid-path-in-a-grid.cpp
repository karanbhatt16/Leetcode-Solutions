class Solution {
public:
    vector<vector<vector<int>>> dir = {
        {},
        {{0,-1},{0,1}},      // 1
        {{-1,0},{1,0}},      // 2
        {{0,-1},{1,0}},      // 3
        {{0,1},{1,0}},       // 4
        {{0,-1},{-1,0}},     // 5
        {{0,1},{-1,0}}       // 6
    };

    bool isValid(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if (i == n - 1 && j == m - 1) {
            return true;
        }

        vis[i][j] = 1;
        for (auto direction : dir[grid[i][j]]) {
            int nx = direction[0] + i;
            int ny = direction[1] + j;

            if (!isValid(nx, ny, n, m) || vis[nx][ny]) continue;

            for (auto back : dir[grid[nx][ny]]) {
                if (nx + back[0] == i && ny + back[1] == j) {
                    vis[nx][ny] = 1;
                    if (dfs(grid, vis, nx, ny)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(grid, vis, 0, 0);
    }
};