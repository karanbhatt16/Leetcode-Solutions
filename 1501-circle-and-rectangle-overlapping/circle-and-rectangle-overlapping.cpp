class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xn, yn;
        if (xCenter < x1) xn = x1;
        else if (xCenter > x2) xn = x2;
        else xn = xCenter;

        if (yCenter < y1) yn = y1;
        else if (yCenter > y2) yn = y2;
        else yn = yCenter;

        return (xn - xCenter) * (xn - xCenter) + (yn - yCenter) * (yn - yCenter) <= radius * radius;
    }
};