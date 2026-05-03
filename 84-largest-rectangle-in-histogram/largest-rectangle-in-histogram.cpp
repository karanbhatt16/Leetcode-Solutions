class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        int pse;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int nse = i;
                int curr = heights[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                ans = max(ans, curr * (nse - pse - 1));
            }

            if (st.empty()) pse = -1;
            else pse = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            int curr = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            ans = max(ans, curr * (n - pse - 1));
        }
        return ans;
    }
};