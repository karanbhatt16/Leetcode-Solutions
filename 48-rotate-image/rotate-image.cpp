class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            vector<int> temp;
            for (int i = m - 1; i >= 0; i--) {
                temp.push_back(matrix[i][j]);
            }
            matrix.push_back(temp);
        }
        for (int i = 0; i < m; i++) {
            matrix.erase(matrix.begin());
        }
    }
};