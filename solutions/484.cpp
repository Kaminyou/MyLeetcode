class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans;
        stack<int> st;
        int num = 1;
        for (auto c : s) {
            st.push(num++);
            if (c == 'I') {
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        st.push(num++);
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};