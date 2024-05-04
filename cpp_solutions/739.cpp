class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        stack<int> st; // monotonic decrease
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int prev = st.top();
                st.pop();
                res[prev] = i - prev;
            }
            st.push(i);
        }
        return res;
    }
};