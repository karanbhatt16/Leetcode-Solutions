class Solution {
private:
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& dis, vector<vector<int>>& vis, int x, int y, int mid) {
        int n = grid.size();
        if (x == n - 1 && y == n - 1) return true;
        vis[x][y] = 1;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        bool ans = false;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && dis[nx][ny] >= mid) {
                ans = ans | dfs(grid, dis, vis, nx, ny, mid);
                if (ans) return true;
            }
        }
        return ans;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int mx = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && dis[nx][ny] == -1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                    mx = max(mx, dis[nx][ny]);
                }
            }
        }

        int low = 0;
        int high = min({mx, dis[0][0], dis[n - 1][n - 1]});
        if (high < 0) high = 0;
        int ans = 0;

        while (low <= high) {
            vector<vector<int>> vis(n, vector<int>(n, 0));
            int mid = (low + high) >> 1;
            if (dis[0][0] >= mid && dfs(grid, dis, vis, 0, 0, mid)) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};