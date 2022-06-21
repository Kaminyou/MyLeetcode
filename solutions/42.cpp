class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int idx = st.top();
                st.pop();
                if (!st.empty()) {
                    int beforeIdx = st.top();
                    int h = min(height[beforeIdx], height[i]) - height[idx];
                    int w = i - beforeIdx - 1;
                    res += h * w;
                }
            }
            st.push(i);
        }
        return res;
    }
};