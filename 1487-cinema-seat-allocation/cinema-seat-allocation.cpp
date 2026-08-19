class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        int m = reservedSeats.size();
        int count = 0;
        int prevrow = 1;
        for (int i = 0; i < m; i++) {
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];
            int one = 1;
            int two = 1;
            int three = 1;
            while (i < m && row == prevrow) {
                if (col > 1 && col <= 5) {
                    one = 0;
                }
                if (col > 3 && col <= 7) {
                    two = 0;
                }
                if (col > 5 && col <= 9) {
                    three = 0;
                }
                i++;
                if (i < m) {
                    row = reservedSeats[i][0];
                    col = reservedSeats[i][1];
                }
            }
            count += (row - prevrow - 1) * 2;
            if (i < m) {
                prevrow = reservedSeats[i][0];
            }

            i--;
            if (one && two && three) count += 2;
            else if ((one && two) || (two && three) || (three && one)) count++;
            else if (one && three) count += 2;
            else if (one || two || three) count++;
        }
        count += (n - prevrow + 1) * 2;
        return count;
    }
};