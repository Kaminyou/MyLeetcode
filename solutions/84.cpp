class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                int currHeight = heights[st.top()];
                st.pop();
                int currWidth = i - st.top() - 1;
                res = max(res, currHeight * currWidth);
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int currHeight = heights[st.top()];
            st.pop();
            int currWidth = n - st.top() - 1;
            res = max(res, currHeight * currWidth);
        }
        return res;
    }
};