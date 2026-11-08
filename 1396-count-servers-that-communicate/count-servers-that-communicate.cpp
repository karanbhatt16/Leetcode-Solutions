class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n);
        vector<int> col(m);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) count++;
            }
            row[i] = count;
        }
        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) count++;
            }
            col[j] = count;
        }
        int ans = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) total++;
                if (grid[i][j] == 1 && row[i] == 1 && col[j] == 1) ans++;
            }
        }
        return total - ans;
    }
};