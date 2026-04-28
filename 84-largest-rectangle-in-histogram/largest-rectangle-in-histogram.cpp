class Solution {
private:
    vector<int> minimum(vector<int>& heights, int start, int end) {
        int minidx = start;
        vector<int> ans;
        for (int i = start; i <= end; i++) {
            if (heights[i] < heights[minidx]) {
                minidx = i;
            }
        }
        for (int i = start; i <= end; i++) {
            if (heights[i] == heights[minidx]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    int solve(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return heights[start];
        }
        vector<int> mins = minimum(heights, start, end);
        int maximum = 0;
        int copy = start;
        for (int i = 0; i < mins.size(); i++) {
            int ans = solve(heights, start, mins[i] - 1);
            maximum = max(maximum, ans);
            start = mins[i] + 1;
        }
        int ans = solve(heights, start, end);
        maximum = max(maximum, ans);
        return max(maximum, heights[mins[0]] * (end - copy + 1));
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        return solve(heights, 0, n - 1);
    }
};