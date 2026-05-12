class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int length = tasks.size();
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (cnt < tasks[i][1]) {
                ans += tasks[i][1] - cnt;
                cnt = tasks[i][1] - tasks[i][0];
            } else {
                cnt = cnt - tasks[i][0];
            }
        }
        return ans;
    }
};