class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = 0;
        int right = n - 1;
        int currcolor = colors[0];
        int idx = -1;
        while (left <= right) {
            if (colors[left] != colors[right]) {
                if (colors[left] != currcolor) {
                    idx = left;
                    break;
                }
                idx = right;
                break;
            } else if (colors[left] != currcolor) {
                idx = left;
                break;
            } else if (colors[right] != currcolor) {
                idx = right;
                break;
            }
            currcolor = colors[left];
            left++;
            right--;
        }
        if (idx == -1) {
            return -1;
        }
        return abs(max(idx - 0, n - idx - 1));
    }
};