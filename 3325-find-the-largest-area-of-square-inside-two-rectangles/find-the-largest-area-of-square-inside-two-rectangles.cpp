class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        for (int i = 0; i < topRight.size(); i++) {
            int temp = bottomLeft[i][1];
            bottomLeft[i][1] = topRight[i][0];
            topRight[i][0] = temp;
        }
        long long ans = 0;
        for (int i = 0; i < topRight.size(); i++) {
            for (int j = i + 1; j < topRight.size(); j++) {
                if (topRight[j][0] < topRight[i][1] && topRight[j][0] >= topRight[i][0]) {
                    if (bottomLeft[j][0] < bottomLeft[i][1] && bottomLeft[j][0] >= bottomLeft[i][0]) {
                        int length1 = topRight[j][1] - topRight[j][0];
                        int length2 = topRight[i][1] - topRight[j][0];
                        int length = length1 < length2 ? length1 : length2;
                        int height1 = bottomLeft[j][1] - bottomLeft[j][0];
                        int height2 = bottomLeft[i][1] - bottomLeft[j][0];
                        int height = height1 < height2 ? height1 : height2;
                        long long side = min(length, height);
                        long long area = side * side;
                        ans = max(area, ans);
                    }
                    if (bottomLeft[j][0] <= bottomLeft[i][0] && bottomLeft[j][1] > bottomLeft[i][0]) {
                        int length1 = topRight[j][1] - topRight[j][0];
                        int length2 = topRight[i][1] - topRight[j][0];
                        int length = length1 < length2 ? length1 : length2;
                        int height1 = bottomLeft[j][1] - bottomLeft[i][0];
                        int height2 = bottomLeft[i][1] - bottomLeft[i][0];
                        int height = height1 < height2 ? height1 : height2;
                        long long side = min(length, height);
                        long long area = side * side;
                        ans = max(area, ans);
                    }
                }
                if (topRight[j][0] <= topRight[i][0] && topRight[j][1] > topRight[i][0]) {
                    if (bottomLeft[j][0] <= bottomLeft[i][0] && bottomLeft[j][1] > bottomLeft[i][0]) {
                        int length1 = topRight[j][1] - topRight[i][0];
                        int length2 = topRight[i][1] - topRight[i][0];
                        int length = length1 < length2 ? length1 : length2;
                        int height1 = bottomLeft[j][1] - bottomLeft[i][0];
                        int height2 = bottomLeft[i][1] - bottomLeft[i][0];
                        int height = height1 < height2 ? height1 : height2;
                        long long side = min(length, height);
                        long long area = side * side;
                        ans = max(area, ans);
                    }
                    if (bottomLeft[j][0] < bottomLeft[i][1] && bottomLeft[j][0] >= bottomLeft[i][0]) {
                        int length1 = topRight[j][1] - topRight[i][0];
                        int length2 = topRight[i][1] - topRight[i][0];
                        int length = length1 < length2 ? length1 : length2;
                        int height1 = bottomLeft[j][1] - bottomLeft[j][0];
                        int height2 = bottomLeft[i][1] - bottomLeft[j][0];
                        int height = height1 < height2 ? height1 : height2;
                        long long side = min(length, height);
                        long long area = side * side;
                        ans = max(area, ans);
                    }
                }
            }
        }
        return ans;
    }
};