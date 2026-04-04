class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int minimum = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (capacity[i] >= itemSize) {
                if (capacity[i] - itemSize < minimum) {
                    idx = i;
                    minimum = capacity[i] - itemSize;
                }
            }
        }
        return idx;
    }
};