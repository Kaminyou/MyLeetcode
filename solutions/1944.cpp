class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            int count = 0;
            while (!st.empty() && curr > st.top()) {
                count++;
                st.pop();
            }
            if (!st.empty()) count++;
            res[i] = count;
            st.push(curr);
        }
        return res;
    }
};