class Solution {
private:

    vector<int> nse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = pse(heights);
        vector<int> right = nse(heights);
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};