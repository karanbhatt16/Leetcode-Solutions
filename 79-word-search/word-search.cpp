class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int x, int y, string& word, int i) {
        if (i >= word.size()) return true;
        vis[x][y] = 1;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && word[i] == board[nx][ny] && !vis[nx][ny]) {
                ans = ans | dfs(board, vis, nx, ny, word, i + 1);
                if (ans == true) return true;
            }
        }
        vis[x][y] = 0;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    start.push_back({i, j});
                }
            }
        }

        vector<vector<int>> vis(m, vector<int> (n, 0));
        for (int i = 0; i < start.size(); i++) {
            if (dfs(board, vis, start[i].first, start[i].second, word, 1)) {
                return true;
            }
        }
        return false;
    }
};