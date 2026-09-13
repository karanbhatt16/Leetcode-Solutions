class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int i = 1 - n; i < n; i++) {
            for (int j = 1 - n; j < n; j++) {
                int count = 0;
                for (int row = 0; row < n; row++) {
                    for (int col = 0; col < n; col++) {
                        int nr = row + i;
                        int nc = col + j;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && img1[nr][nc] == img2[row][col] && img2[row][col] == 1) {
                            count++;
                        }
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};