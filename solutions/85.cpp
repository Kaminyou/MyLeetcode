class Solution {
public:
    int maxArea = 0;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') dp[j] += 1;
                else dp[j] = 0;
            }
            maxHistogram(dp);
        }
        return maxArea;
    }
    void maxHistogram(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && heights[st.top()] > heights[i]) {
                int currentHeight = heights[st.top()];
                st.pop();
                int currentWidth = i - 1 - st.top();
                maxArea = max(maxArea, currentHeight * currentWidth);
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int currentHeight = heights[st.top()];
            st.pop();
            int currentWidth = n - 1 - st.top();
            maxArea = max(maxArea, currentHeight * currentWidth);
        }
    }
};
