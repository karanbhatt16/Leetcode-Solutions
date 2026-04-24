class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0;
        int n = moves.length();
        for (int i = 0; i < n; i++) {
            if (moves[i] == 'R') {
                r++;
            } else if (moves[i] == 'L') {
                l++;
            }
        }
        if (l > r) {
            return n - (2 * r);
        } else {
            return n - (2 * l);
        }
    }
};