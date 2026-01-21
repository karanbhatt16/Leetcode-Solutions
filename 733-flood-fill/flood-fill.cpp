class Solution {
private:
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int pixel) {
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();
        if ((sr != 0) && (image[sr - 1][sc] == pixel)) {
            solve(image, sr - 1, sc, color, pixel);
        }
        if ((sc != 0) && (image[sr][sc - 1] == pixel)) {
            solve(image, sr, sc - 1, color, pixel);
        }
        if ((sr != m - 1) && (image[sr + 1][sc] == pixel)) {
            solve(image, sr + 1, sc, color, pixel);
        }
        if ((sc != n - 1) && (image[sr][sc + 1] == pixel)) {
            solve(image, sr, sc + 1, color, pixel);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pixel = image[sr][sc];
        if (pixel != color) {
            solve(image, sr, sc, color, pixel);
        }
        return image;
    }
};