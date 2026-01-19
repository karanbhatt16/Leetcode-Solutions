class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> prefixSum(mat.begin(), mat.end());
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                prefixSum[i][j] += prefixSum[i][j - 1];
            }
        }
        int side = min(row, col);
        for (int k = side; k >= 1; k--) {
            for (int i = 0; i + k - 1 < row; i++) {
                for (int j = 0; j + k - 1 < col; j++) {
                    int sum = 0;
                    for (int x = 0; x < k; x++) {
                        sum += (prefixSum[i + x][j + k - 1] - prefixSum[i + x][j] + mat[i + x][j]);
                        if (sum > threshold) {
                            break;
                        }
                    }
                    if (sum <= threshold) {
                        return k;
                    }
                }
            }
        }
        return 0;
    }
};