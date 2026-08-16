class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++) {
            if (stones[i] % 3 == 0) zero++;
            else if (stones[i] % 3 == 1) one++;
            else two++;
        }

        zero = zero % 2;
        if (zero == 0) {
            if (one == 0 || two == 0) {
                return false;
            }
            return true;
        } else {
            if (abs(one - two) > 2) {
                return true;
            }
            return false;
        }
    }
};