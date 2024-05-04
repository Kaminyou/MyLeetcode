class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> st;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] >= heights[st.back()]) st.pop_back();
            st.push_back(i);
        }
        return st;
    }
};