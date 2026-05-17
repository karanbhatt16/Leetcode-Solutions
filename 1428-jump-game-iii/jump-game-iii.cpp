class Solution {
private:
    bool solve(vector<int>& arr, vector<int>& vis, int start) {
        if (vis[start] == 1) {
            return false;
        }
        vis[start] = 1;
        if (arr[start] == 0) {
            return true;
        }
        int left = start - arr[start];
        int right = start + arr[start];
        int n = arr.size();
        if (left >= 0) {
            if (solve(arr, vis, left)) {
                return true;
            }
        }
        if (right < n) {
            if (solve(arr, vis, right)) {
                return true;
            }
        }
        vis[start] = 0;
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return solve(arr, vis, start);
    }
};