class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0;
        int n = citations.size();
        int high = n - 1;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (n - mid <= citations[mid]) {
                high = mid - 1;
                ans = n - mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};