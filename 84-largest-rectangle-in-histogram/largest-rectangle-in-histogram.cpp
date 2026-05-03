class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        vector<int> pse;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                ans = max(ans, heights[st.top()] * (i - pse[st.top()] - 1));
                st.pop();
            }

            if (st.empty()) pse.push_back(-1);
            else pse.push_back(st.top());
            st.push(i);
        }
        while (!st.empty()) {
            ans = max(ans, heights[st.top()] * (n - 1 - pse[st.top()]));
            st.pop();
        }
        return ans;
    }
};