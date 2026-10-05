class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int curr = 0;
        for (auto& c : s) {
            if (c == ')') {
                if (curr == 0) curr = 1;
                else curr *= 2;
                curr += st.top();
                st.pop();
            }
            else {
                st.push(curr);
                curr = 0;
            }
        }
        return curr;
    }
};
