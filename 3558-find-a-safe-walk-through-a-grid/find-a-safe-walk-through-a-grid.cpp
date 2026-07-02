class Solution {
private:
    bool dfs(vector<vector<int>>& grid, int health, vector<vector<int>>& best, int x, int y) {
        if (grid[x][y] == 1) {
            health--;
        }
        if (health <= best[x][y])
            return false;

        best[x][y] = health;
        int n = grid.size();
        int m = grid[0].size();
        if (x == n - 1 && y == m - 1) return true;

        vector<int> dirx = {0, 1, 0, -1};
        vector<int> diry = {1, 0, -1, 0};
        bool ans = false;

        for (int i = 0; i < 4; i++) {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && best[nx][ny] < health) {
                ans = ans | dfs(grid, health, best, nx, ny);
                if (ans == true) {
                    return true;
                }
            }
        }
        return ans;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> best(n, vector<int> (m, 0));
        return dfs(grid, health, best, 0, 0);
    }
};