class Solution {
private:
    vector<vector<int>> row, col, box;

    bool solve(vector<vector<char>>& board, vector<pair<int,int>>& empty, int idx) {
        if (idx == empty.size()) return true;

        int r = empty[idx].first;
        int c = empty[idx].second;
        int b = (r/3)*3 + (c/3);

        for (int d = 0; d < 9; d++) {
            if (!row[r][d] && !col[c][d] && !box[b][d]) {

                // place
                board[r][c] = d + '1';
                row[r][d] = col[c][d] = box[b][d] = 1;

                if (solve(board, empty, idx + 1)) return true;

                // backtrack
                board[r][c] = '.';
                row[r][d] = col[c][d] = box[b][d] = 0;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        row.assign(9, vector<int>(9, 0));
        col.assign(9, vector<int>(9, 0));
        box.assign(9, vector<int>(9, 0));

        vector<pair<int,int>> empty;

        // initialize
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    empty.push_back({i,j});
                } else {
                    int d = board[i][j] - '1';
                    row[i][d] = 1;
                    col[j][d] = 1;
                    box[(i/3)*3 + (j/3)][d] = 1;
                }
            }
        }

        solve(board, empty, 0);
    }
};