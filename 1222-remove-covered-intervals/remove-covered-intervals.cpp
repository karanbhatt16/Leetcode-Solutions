class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });

        stack<int> st;

        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            while(!st.empty() && intervals[i][0] <= st.top()) {
                st.pop();
            }
            st.push(intervals[i][0]);
        }

        return st.size();
    }
};